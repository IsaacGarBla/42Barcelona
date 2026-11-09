from enum import Enum
import re

from errors import ParseException, GraphException
from graph import Graph, Hub
from common import Colour, Coordinate, ZoneType


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
    def _process_nb_drones(tokens: re.Match, n_line: int,
                           g: Graph) -> None:
        g.nb_drones = int(tokens.group(1))
        print(f"Número de drones: {int(tokens.group(1))}")

    @staticmethod
    def _process_start_hub(tokens: re.Match, n_line: int,
                           g: Graph) -> None:
        coord:  Coordinate = Coordinate(int(tokens.group("x")),
                                        int(tokens.group("y")))
        color:      Colour = Colour.NONE
        zone:       ZoneType = ZoneType.INI
        max_drones: int = 100

        try:
            if tokens.group("color"):
                color = Colour[tokens.group("color").upper()]

            g.add_hub(Hub(tokens.group("hub_name"),
                          coord, zone, max_drones, color))
            g.start_hub = tokens.group("hub_name")
        except GraphException as e:
            raise ParseException(str(e), n_line)

        print(f"Start hub: {tokens.group('hub_name')}, "
              f"position: {tokens.group('x')}, {tokens.group('y')}, "
              f"color: {tokens.group('color')}")

    @staticmethod
    def _process_hub(tokens: re.Match, n_line: int,
                     g: Graph) -> None:
        coord:  Coordinate = Coordinate(int(tokens.group("x")),
                                        int(tokens.group("y")))
        color:      Colour = Colour.NONE
        zone:       ZoneType = ZoneType.NORMAL
        max_drones: int = 1

        if tokens.group("color"):
            color = Colour[tokens.group("color").upper()]
        if tokens.group("zone"):
            zone = ZoneType[tokens.group("zone").upper()]
        if tokens.group("max_drones"):
            max_drones = int(tokens.group("max_drones"))

        try:
            g.add_hub(Hub(tokens.group("hub_name"),
                      coord, zone, max_drones, color))
        except GraphException as e:
            raise ParseException(str(e), n_line)

        print(f"Hub: {tokens.group('hub_name')}, "
              f"position: {tokens.group('x')}, {tokens.group('y')}, "
              f"color: {tokens.group('color')}, "
              f"zone: {tokens.group('zone')}, "
              f"max_drones: {tokens.group('max_drones')}")

    @staticmethod
    def _process_end_hub(tokens: re.Match,  n_line: int,
                         g: Graph) -> None:
        coord:  Coordinate = Coordinate(int(tokens.group("x")),
                                        int(tokens.group("y")))
        color:      Colour = Colour.NONE
        zone:       ZoneType = ZoneType.INI
        max_drones: int = 100

        try:
            if tokens.group("color"):
                color = Colour[tokens.group("color").upper()]

            g.add_hub(Hub(tokens.group("hub_name"),
                          coord, zone, max_drones, color))
            g.end_hub = tokens.group("hub_name")
        except GraphException as e:
            raise ParseException(str(e), n_line)

        print(f"End hub: {tokens.group('hub_name')}, "
              f"position: {tokens.group('x')}, {tokens.group('y')}, "
              f"color: {tokens.group('color')}")

    @staticmethod
    def _process_connection(tokens: re.Match, n_line: int,
                            g: Graph) -> None:
        capacity:   int = 1

        try:
            if tokens.group("capacity"):
                capacity = int(tokens.group("capacity"))

            g.add_connection(tokens.group("hub_name1"),
                             tokens.group("hub_name2"),
                             capacity)
        except GraphException as e:
            raise ParseException(str(e), n_line)

        print(f"Start hub: {tokens.group('hub_name1')}, "
              f"end hub: {tokens.group('hub_name2')}, "
              f"capacity: {tokens.group('capacity')}")

    @staticmethod
    def parse(file_path: str) -> Graph:
        state:              Parser._State = Parser._State.READ_NUMBER_DRONES
        state_processed:    bool
        n_line:             int = 0
        new_graph:          Graph = Graph()
        hubs:               int = 0
        graph_completed:    bool = False
        parser_error:              bool = False

        # Open file for reading
        with open(file_path, 'r') as file:
            for line in file:
                n_line += 1
                line = line.strip()
                # Skip comments and blank lines
                if not line or line.startswith("#"):
                    continue
                state_processed = False
                while not state_processed and not parser_error:
                    match state:
                        case Parser._State.READ_NUMBER_DRONES:
                            tokens = re.match(Parser._Pattern.NB_DRONES.value,
                                              line.strip())
                            if tokens:
                                state = Parser._State.READ_START_HUB
                                Parser._process_nb_drones(tokens, n_line,
                                                          new_graph)
                                state_processed = True
                            else:
                                parser_error = True
                        case Parser._State.READ_START_HUB:
                            tokens = re.match(Parser._Pattern.START_HUB.value,
                                              line.strip())
                            if tokens:
                                state = Parser._State.READ_HUBS
                                Parser._process_start_hub(tokens, n_line,
                                                          new_graph)
                                state_processed = True
                            else:
                                parser_error = True
                        case Parser._State.READ_HUBS:
                            tokens = re.match(Parser._Pattern.HUB.value,
                                              line.strip())
                            if tokens:
                                Parser._process_hub(tokens, n_line, new_graph)
                                state_processed = True
                                hubs += 1
                            else:
                                if hubs == 0:
                                    parser_error = True
                                else:
                                    state = Parser._State.READ_END_HUB
                        case Parser._State.READ_END_HUB:
                            tokens = re.match(Parser._Pattern.END_HUB.value,
                                              line.strip())
                            if tokens:
                                state = Parser._State.READ_CONNECTIONS
                                Parser._process_end_hub(tokens, n_line,
                                                        new_graph)
                                state_processed = True
                            else:
                                parser_error = True
                        case Parser._State.READ_CONNECTIONS:
                            tokens = re.match(Parser._Pattern.CONNECTION.value,
                                              line.strip())
                            if tokens:
                                Parser._process_connection(tokens, n_line,
                                                           new_graph)
                                state_processed = True
                                graph_completed = True
                            else:
                                parser_error = True
                # If there is an error parsin the file, stops reading lines.
                if parser_error:
                    break

        if not graph_completed or parser_error:
            match state:
                case Parser._State.READ_START_HUB:
                    raise ParseException("Start-hub was expected",
                                         n_line)
                case Parser._State.READ_END_HUB:
                    raise ParseException("End-hub was "
                                         "expected ", n_line)
                case Parser._State.READ_HUBS:
                    raise ParseException("Hub was "
                                         "expected ", n_line)
                case Parser._State.READ_CONNECTIONS:
                    raise ParseException("Connection was expected",
                                         n_line)
                case Parser._State.READ_NUMBER_DRONES:
                    raise ParseException("Drone number was"
                                         "expected. Negative numbers "
                                         "aren't allowed", n_line)
        return new_graph
