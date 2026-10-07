class ParserError(Exception):
    """Base exception for all configuration parsing errors.

    All custom parser exceptions inherit from this class,
    allowing callers to catch any parsing error with a single
    except ParserError clause.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "General error during configuration parsing."
                 ) -> None:
        super().__init__(text)


class InvalidArgumentsError(ParserError):
    """Raised when the command-line arguments are invalid.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "Usage: python3 a_maze_ing.py config.txt"
                 ) -> None:
        super().__init__(text)


class ConfigFileNotFoundError(ParserError):
    """Raised when the configuration file cannot be found or read.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "Configuration file not found."
                 ) -> None:
        super().__init__(text)


class ConfigSyntaxError(ParserError):
    """Raised when a line in the configuration file has invalid syntax.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "Invalid syntax in configuration file."
                 ) -> None:
        super().__init__(text)


class MissingMandatoryKeyError(ParserError):
    """Raised when a required key is absent from the configuration.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "Missing mandatory key in configuration."
                 ) -> None:
        super().__init__(text)


class InvalidValueError(ParserError):
    """Raised when a configuration key holds a value of an unexpected type.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "Invalid value type in configuration."
                 ) -> None:
        super().__init__(text)


class InvalidMazeBoundsError(ParserError):
    """Raised when maze coordinates or dimensions are not correct.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self, text: str = "Maze coordinates or "
                                   "dimensions are out of bounds.") -> None:
        super().__init__(text)
