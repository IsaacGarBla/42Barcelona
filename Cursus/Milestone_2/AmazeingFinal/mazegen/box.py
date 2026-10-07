class Box:
    """Represents a single cell in the maze grid.

    Each cell tracks its wall configuration, whether it is blocked
    (reserved for the logo), and whether it belongs to the solution path.

    Attributes:
        _walls: Bitmask of active walls using Direction constants.
        _blocked: Whether this cell is reserved and excluded from generation.
        _is_path: Whether this cell is part of the solution path.
    """

    _walls: int
    _blocked: bool
    _is_path: bool

    def __init__(self, walls: int, visited: bool = False,
                 blocked: bool = False) -> None:
        """Initializes a Box with a wall configuration and optional state.

        Args:
            walls: Bitmask of initial walls (e.g., Direction.ALL_WALLS).
            visited: Unused parameter, reserved for future use.
            blocked: Whether the cell starts as blocked.
        """
        self._walls = walls
        self._blocked = blocked
        self._is_path = False

    def block(self) -> None:
        """Marks this cell as blocked, excluding it from maze generation."""
        self._blocked = True

    def unblock(self) -> None:
        """Removes the blocked state, allowing this cell to be used."""
        self._blocked = False

    def is_blocked(self) -> bool:
        """Returns whether this cell is blocked.

        Returns:
            True if the cell is blocked, False otherwise.
        """
        return self._blocked

    def set_as_path(self) -> None:
        """Marks this cell as part of the solution path."""
        self._is_path = True

    def set_as_no_path(self, id_path: int | None = None) -> None:
        """Removes this cell from the solution path.

        Args:
            id_path: Unused parameter, reserved for future use.
        """
        self._is_path = False

    def is_path(self, id_path: int | None = None) -> bool:
        """Returns whether this cell is part of the solution path.

        Args:
            id_path: Unused parameter, reserved for future use.

        Returns:
            True if the cell is on the solution path, False otherwise.
        """
        return self._is_path

    def set_walls(self, walls: int) -> None:
        """Sets the wall configuration of this cell.

        Args:
            walls: Bitmask of walls to assign
            (e.g., Direction.NORTH | Direction.EAST).
        """
        self._walls = walls

    def get_walls(self) -> int:
        """Returns the current wall configuration of this cell.

        Returns:
            Bitmask of active walls using Direction constants.
        """
        return self._walls
