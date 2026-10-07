from .dimension import Dimension


class AreaLogo:
    """Stores the visual pattern for the maze logo.

    Attributes:
        _dimension: Grid size of the logo (5 cols x 7 rows).
        _pattern: 2D boolean matrix where True represents an active cell.
    """

    _dimension: Dimension
    _pattern: list[list[bool]]

    def __init__(self) -> None:
        """Initializes the logo with a fixed 5x7 pattern."""
        self._dimension = Dimension(5, 7)
        self._pattern = [[True, False, False, False, True, True, True],
                         [True, False, True, False, False, False, True],
                         [True, True, True, False, True, True, True],
                         [False, False, True, False, True, False, False],
                         [False, False, True, False, True, True, True]]

    @property
    def dimension(self) -> Dimension:
        """Returns the dimensions of the logo grid."""
        return self._dimension

    @property
    def pattern(self) -> list[list[bool]]:
        """Returns the 2D boolean pattern of the logo."""
        return self._pattern
