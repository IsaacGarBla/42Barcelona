class Dimension:
    """Represents the size of a 2D area in the maze.

    Attributes:
        _width: Number of columns.
        _height: Number of rows.
    """

    _width: int
    _height: int

    def __init__(self, height: int = 0, width: int = 0) -> None:
        """Initializes a Dimension with the given height and width.

        Args:
            height: Number of rows. Defaults to 0.
            width: Number of columns. Defaults to 0.
        """
        self._width = width
        self._height = height

    @property
    def height(self) -> int:
        """Returns the number of rows."""
        return self._height

    @height.setter
    def height(self, height: int) -> None:
        """Sets the number of rows.

        Args:
            height: New row count.
        """
        self._height = height

    @property
    def width(self) -> int:
        """Returns the number of columns."""
        return self._width

    @width.setter
    def width(self, width: int) -> None:
        """Sets the number of columns.

        Args:
            width: New column count.
        """
        self._width = width
