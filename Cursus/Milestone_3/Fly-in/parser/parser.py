from enum import Enum
from typing import TextIO
import re

from errors import ParseException
from graph import Graph


class Parser:

    class _State(Enum):
        READ_NUMBER_DRONES = 0
        READ_START_HUB = 1
        READ_HUBS = 2
        READ_END_HUB = 3
        READ_CONNECTIONS = 4

    class _Pattern(Enum):
        NB_DRONES = r"^nb_drones:\s+(?P<nb_drones>[0-9]+)\s*$"
        START_HUB = (r"^start_hub:\s+(?P<hub_name>[^-\s]+)\s+"
                     r"(?P<x>-?[0-9]+)\s+(?P<y>-?[0-9]+)"
                     r"(\s+\[\s*color=(?P<color>[a-zA-Z]+)\s*\])?\s*$")
        END_HUB = (r"^end_hub:\s+(?P<hub_name>[^-\s]+)\s+"
                   r"(?P<x>-?[0-9]+)\s+(?P<y>-?[0-9]+)"
                   r"(\s+\[\s*color=(?P<color>[a-zA-Z]+)\s*\])?\s*$")
        HUB = (r"^hub:\s+(?P<hub_name>[^-\s]+)\s+"
               r"(?P<x>-?[0-9]+)\s+(?P<y>-?[0-9]+)"
               r"(\s+\["
               r"(?=\s*([^\]]*?\bzone=(?P<zone>priority|"
               r"normal|blocked|restricted)\b)?)"
               r"(?=\s*([^\]]*?\bcolor=(?P<color>[a-zA-Z]+)\b)?)"
               r"(?=\s*([^\]]*?\bmax_drones="
               r"(?P<max_drones>[0-9]+)\b)?)"
               r"[^\]]*\])?\s*$")
        CONNECTION = (r"^connection:\s+(?P<hub_name1>[^-\s]+)\-"
                      r"(?P<hub_name2>[^-\s]+)"
                      r"(\s+\[\s*max_link_capacity=(?P<capacity>"
                      r"[0-9]+)\s*\])?\s*$")

    @staticmethod
    def _process_nb_drones(tokens: re.Match, n_line: int) -> None:
        print(f"Número de drones: {int(tokens.group(1))}")

    @staticmethod
    def _process_start_hub(tokens: re.Match, n_line: int) -> None:
        print(f"Start hub: {tokens.group("hub_name")}, "
              f"position: {tokens.group("x")}, {tokens.group("y")}, "
              f"color: {tokens.group("color")}")

    @staticmethod
    def _process_hub(tokens: re.Match, n_line: int) -> None:
        print(f"Hub: {tokens.group("hub_name")}, "
              f"position: {tokens.group("x")}, {tokens.group("y")}, "
              f"color: {tokens.group("color")}, "
              f"zone: {tokens.group("zone")}, "
              f"max_drones: {tokens.group("max_drones")}")

    @staticmethod
    def _process_end_hub(tokens: re.Match,  n_line: int) -> None:
        print(f"End hub: {tokens.group("hub_name")}, "
              f"position: {tokens.group("x")}, {tokens.group("y")}, "
              f"color: {tokens.group("color")}")

    @staticmethod
    def _process_connection(tokens: re.Match, n_line: int) -> None:
        print(f"Start hub: {tokens.group("hub_name1")}, "
              f"end hub: {tokens.group("hub_name2")}, "
              f"capacity: {tokens.group("capacity")}")
        return True

    @staticmethod
    def parse(file_path: str) -> Graph:
        state:  Parser._State = Parser._State.READ_NUMBER_DRONES.value
        file:               TextIO
        state_processed:    bool
        n_line:             int = 0
        new_graph:          Graph = Graph()

        # Open file for reading
        with open(file_path, 'r') as file:
            for line in file:
                n_line += 1
                # Skip comments and blank lines
                if line.startswith("#") or not line.strip():
                    continue
                state_processed = False
                print(f"Linea leída: {line}")
                while not state_processed:
                    match state:
                        case Parser._State.READ_NUMBER_DRONES.value:
                            tokens = re.match(Parser._Pattern.NB_DRONES.value,
                                              line.strip())
                            if tokens:
                                state = Parser._State.READ_START_HUB.value
                                Parser._process_nb_drones(tokens, n_line)
                                state_processed = True
                            else:
                                raise ParseException("Drone number was"
                                                     "expected", n_line)
                        case Parser._State.READ_START_HUB.value:
                            tokens = re.match(Parser._Pattern.START_HUB.value,
                                              line.strip())
                            if tokens:
                                state = Parser._State.READ_HUBS.value
                                Parser._process_start_hub(tokens, n_line)
                                state_processed = True
                            else:
                                raise ParseException("Start-hub was expected",
                                                     n_line)
                        case Parser._State.READ_HUBS.value:
                            tokens = re.match(Parser._Pattern.HUB.value,
                                              line.strip())
                            if tokens:
                                state = Parser._State.READ_HUBS.value
                                Parser._process_hub(tokens, n_line)
                                state_processed = True
                            else:
                                tokens = re.match(
                                            Parser._Pattern.END_HUB.value,
                                            line.strip())
                                if tokens:
                                    state = Parser._State.READ_END_HUB.value
                                else:
                                    raise ParseException("Hub or end-hub was "
                                                         "expected ", n_line)
                        case Parser._State.READ_END_HUB.value:
                            tokens = re.match(Parser._Pattern.END_HUB.value,
                                              line.strip())
                            if tokens:
                                state = Parser._State.READ_CONNECTIONS.value
                                Parser._process_end_hub(tokens, n_line)
                                state_processed = True
                        case Parser._State.READ_CONNECTIONS.value:
                            tokens = re.match(Parser._Pattern.CONNECTION.value,
                                              line.strip())
                            if tokens:
                                Parser._process_connection(tokens, n_line)
                                state_processed = True
                            else:
                                raise ParseException("Connectio was expected",
                                                     n_line)
        return new_graph
