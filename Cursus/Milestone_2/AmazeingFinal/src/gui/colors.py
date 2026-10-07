"""Module for managing ANSI color codes and GUI component themes."""

colors = {
    "black": "\033[40m",
    "red": "\033[41m",
    "green": "\033[42m",
    "yellow": "\033[43m",
    "blue": "\033[44m",
    "magenta": "\033[45m",
    "cyan": "\033[46m",
    "white": "\033[47m",
    "bright_black": "\033[100m",
    "bright_red": "\033[101m",
    "bright_green": "\033[102m",
    "bright_yellow": "\033[103m",
    "bright_blue": "\033[104m",
    "bright_magenta": "\033[105m",
    "bright_cyan": "\033[106m",
    "bright_white": "\033[107m",
    "reset": "\033[0m"
}


class ThemeColor:
    """Represents a customizable color theme for visual components.

    Stores and manages ANSI escape sequences associated with various
    visual elements such as borders, background, entry, exit, and paths.
    """

    _border_color: str
    _back_color: str
    _entry_color: str
    _exit_color: str
    _path_color: str
    _logo_color: str
    _pen_color: str

    def __init__(self, border_color: str = colors["cyan"],
                 back_color: str = colors["white"],
                 entry_color: str = colors["bright_green"],
                 exit_color: str = colors["bright_blue"],
                 path_color: str = colors["yellow"],
                 logo_color: str = colors["red"],
                 pen_color: str = colors["green"]) -> None:
        """Initializes a new ThemeColor instance with default or custom colors.

        Args:
            border_color (str, optional): Color code for borders.
            Defaults to cyan.
            back_color (str, optional): Color code for background.
            Defaults to white.
            entry_color (str, optional): Color code for entry marker.
            Defaults to bright green.
            exit_color (str, optional): Color code for exit marker.
            Defaults to bright blue.
            path_color (str, optional): Color code for solution path.
            Defaults to yellow.
            logo_color (str, optional): Color code for the logo.
            Defaults to red.
            pen_color (str, optional): Color code for the drawing pen.
            Defaults to green.
        """
        self._border_color = border_color
        self._back_color = back_color
        self._entry_color = entry_color
        self._exit_color = exit_color
        self._path_color = path_color
        self._logo_color = logo_color
        self._pen_color = pen_color

    @property
    def border_color(self) -> str:
        """str: Gets or sets the border color code."""
        return self._border_color

    @border_color.setter
    def border_color(self, color: str) -> None:
        self._border_color = color

    @property
    def back_color(self) -> str:
        """str: Gets or sets the background color code."""
        return self._back_color

    @back_color.setter
    def back_color(self, color: str) -> None:
        self._back_color = color

    @property
    def entry_color(self) -> str:
        """str: Gets or sets the entry marker color code."""
        return self._entry_color

    @entry_color.setter
    def entry_color(self, color: str) -> None:
        self._entry_color = color

    @property
    def exit_color(self) -> str:
        """str: Gets or sets the exit marker color code."""
        return self._exit_color

    @exit_color.setter
    def exit_color(self, color: str) -> None:
        self._exit_color = color

    @property
    def path_color(self) -> str:
        """str: Gets or sets the solution path color code."""
        return self._path_color

    @path_color.setter
    def path_color(self, color: str) -> None:
        self._path_color = color

    @property
    def logo_color(self) -> str:
        """str: Gets or sets the logo color code."""
        return self._logo_color

    @logo_color.setter
    def logo_color(self, color: str) -> None:
        self._logo_color = color

    @property
    def pen_color(self) -> str:
        """str: Gets or sets the pen stroke color code."""
        return self._pen_color

    @pen_color.setter
    def pen_color(self, color: str) -> None:
        self._pen_color = color
