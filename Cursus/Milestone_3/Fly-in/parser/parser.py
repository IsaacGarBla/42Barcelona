from enum import Enum
from typing import TextIO
import re


class States(Enum):
    READ_NUMBER_DRONES = 0
    READ_START_HUB = 1
    READ_HUBS = 2
    READ_END_HUB = 3
    READ_CONNECTIONS = 4


class Patterns(Enum):
    PATT_NB_DRONES = r"^nb_drones:\s+(?P<nb_drones>[0-9]+)\s*$"
    PATT_START_HUB = (r"^start_hub:\s+(?P<hub_name>[A-Za-z_]+)\s+"
                      r"(?P<x>[0-9]+)\s+(?P<y>[0-9]+)\s*"
                      r"\[\s*color=(?P<color>red|green|"
                      r"yellow|blue|gray)\s*\]?\s*$")
    PATT_END_HUB = (r"^end_hub:\s+(?P<hub_name>[A-Za-z_]+)\s+"
                    r"(?P<x>[0-9]+)\s+(?P<y>[0-9]+)\s*"
                    r"\[\s*color=(?P<color>red|green|"
                    r"yellow|blue|gray)\s*\]?\s*$")
    PATT_HUB = (r"^hub:\s+(?P<hub_name>[A-Za-z_]+)\s+"
                r"(?P<x>[0-9]+)\s+(?P<y>[0-9]+)"
                r"(\s*\["
                r"(?=\s*([^\]]*?\bzone=(?P<zone>priority|"
                r"normal|blocked|restricted)\b)?)"
                r"(?=\s*([^\]]*?\bcolor=(?P<color>red|green|"
                r"yellow|blue|gray)\b)?)"
                r"(?=\s*([^\]]*?\bmax_drones="
                r"(?P<max_drones>[0-9]+)\b)?)"
                r"[^\]]*\])?\s*$")
    PATT_CONNECTION = (r"^connection:\s+(?P<hub_name1>[A-Za-z_]+)\-"
                       r"(?P<hub_name2>[A-Za-z_]+)\s+"
                       r"\[\s*max_link_capacity=(?P<capacity>"
                       r"[0-9]+)\s*\]?\s*$")


def parameters_ok(param: list[str]) -> int:
    """
    Checks if there is only one parameter (the name of the file
    with the map) and it really exists.

    Arg:
        param: list of parameters in the command line

    Return:
        0: if parameters are OK.
        1: if the number of parameters is different of zero.
        2: the filename doesn't exists.
    """
    if len(param != 2):
        return 1
    try:
        with open(param[1], 'r') as file:
            return 0
    except (FileNotFoundError, PermissionError,
            IsADirectoryError, FileExistsError):
        return 2
    return 0


def parse(param: list[str]) -> bool:
    state:              States = States.READ_NUMBER_DRONES
    file:               TextIO

    # Open file for reading
    file = open(param[1], 'r')
    for line in file:
        # Skip comments and blank lines
        if line.startswith("#") or not line.strip():
            continue
        match state:
            case States.READ_NUMBER_DRONES.value:
                tokens = re.match(Patterns.PATT_NB_DRONES.value, line.strip())
                if tokens:
                    state = States.READ_START_HUB.value
                    drones = int(tokens.group(1))
            case States.READ_START_HUB.value:
                tokens = re.match(Patterns.PATT_START_HUB.value, line.strip())
                if tokens:
                    start_hub = tokens.group("hub_name")
                    state = States.READ_HUBS.value
            case States.READ_HUBS.value:
                tokens = re.match(Patterns.PATT_HUB.value, line.strip())
            case States.READ_END_HUB.value:
                tokens = re.match(Patterns.PATT_END_HUB.value, line.strip())
            case States.READ_CONNECTIONS.value:
                tokens = re.match(Patterns.PATT_CONNECTION.value, line.strip())
