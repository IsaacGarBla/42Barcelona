class ErrorMaze(Exception):
    """Base exception for all maze-related errors.

    All custom maze exceptions inherit from this class,
    allowing callers to catch any maze error with a single
    except ErrorMaze clause.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "General error during Maze creation") -> None:
        super().__init__(text)


class MazeExitError(ErrorMaze):
    """Raised when the exit coordinate is invalid or blocked.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "Exit coordinates aren't valid.") -> None:
        super().__init__(text)


class MazeEntryError(ErrorMaze):
    """Raised when the entry coordinate is invalid or blocked.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "Entry coordinates aren't valid.") -> None:
        super().__init__(text)


class MazeDimensionError(ErrorMaze):
    """Raised when the maze dimensions are too small or invalid.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self, text: str = "Dimension isn't valid.") -> None:
        super().__init__(text)


class MazeExportError(ErrorMaze):
    """Raised when the maze cannot be exported to a file.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self, text: str = "Error exporting maze.") -> None:
        super().__init__(text)
