import sys
from parser import Parser
from graph import Graph


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
    if len(param) != 2:
        return 1
    try:
        with open(param[1], 'r') as file:
            return 0
    except (FileNotFoundError, PermissionError,
            IsADirectoryError, FileExistsError):
        return 2
    return 0


if __name__ == "__main__":
    new_graph:  Graph
    match parameters_ok(sys.argv):
        case 0:
            print("Parámetros correctos.")
            new_graph = Parser.parse(sys.argv[1])
            new_graph.start_hub = "pepe"
        case 1:
            print("Número parámetros erróneos.")
        case 2:
            print("No se puede acceder el fichero.")
