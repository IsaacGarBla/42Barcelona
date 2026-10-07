class Coordinate:
    """Represents a 2D position in the maze grid.

    Supports equality comparison and hashing so it can be used
    in sets and as dictionary keys.

    Attributes:
        _x: Column index.
        _y: Row index.
    """

    _y: int
    _x: int

    def __init__(self, x: int = 0, y: int = 0) -> None:
        """Initializes a Coordinate at the given position.

        Args:
            x: Column index. Defaults to 0.
            y: Row index. Defaults to 0.
        """
        self._x = x
        self._y = y

    def __eq__(self, otro: object) -> bool:
        """Checks equality between two Coordinates.

        Args:
            otro: Object to compare against.

        Returns:
            True if both x and y match, False otherwise.
        """
        if not isinstance(otro, Coordinate):
            return False
        return self.x == otro.x and self.y == otro.y

    def __hash__(self) -> int:
        """Returns a hash based on (y, x) for use in sets and dicts.

        Returns:
            Hash of the (y, x) tuple.
        """
        return hash((self._y, self._x))

    @property
    def x(self) -> int:
        """Returns the column index."""
        return self._x

    @x.setter
    def x(self, x: int) -> None:
        """Sets the column index.

        Args:
            x: New column index.
        """
        self._x = x

    @property
    def y(self) -> int:
        """Returns the row index."""
        return self._y

    @y.setter
    def y(self, y: int) -> None:
        """Sets the row index.

        Args:
            y: New row index.
        """
        self._y = y

    def add_offset(self, offset: tuple[int, int]) -> "Coordinate":
        """Returns a new Coordinate shifted by the given offset.

        Args:
            offset: A (dx, dy) tuple to add to the current position.

        Returns:
            A new Coordinate at (x + dx, y + dy).
        """
        return Coordinate(self._x + offset[0], self._y + offset[1])
