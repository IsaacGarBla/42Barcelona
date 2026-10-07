class PrintError(Exception):
    """Base exception for all maze printing errors.

    All custom print exceptions inherit from this class,
    allowing callers to catch any print error with a single
    except PrintError clause.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self,
                 text: str = "General error while printing Maze") -> None:
        super().__init__(text)


class PrintTerminalError(PrintError):
    """Raised when the Terminal is too small to render the maze.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self, text: str = "Terminal isn't valid to draw the Maze."
                 ) -> None:
        super().__init__(text)


class PrintScreenError(PrintError):
    """Raised when the screen is too small to print the maze.

    Args:
        text: Human-readable description of the error.
    """

    def __init__(self, text: str = "Screen isn't valid to draw the Maze."
                 ) -> None:
        super().__init__(text)
