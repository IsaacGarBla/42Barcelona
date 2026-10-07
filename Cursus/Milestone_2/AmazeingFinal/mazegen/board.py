from .coordinate import Coordinate
from .dimension import Dimension
from .box import Box
from .areaLogo import AreaLogo
from .direction import Direction


class Board:
    """Represents the maze grid and manages its cells.

    Attributes:
        _dimension: Width and height of the board in cells.
        _grid: 2D matrix of Box objects, each holding wall state.
        _blocked_boxes: Coordinates of cells blocked by the logo pattern.
    """

    _dimension: Dimension
    _grid: list[list[Box]]
    _blocked_boxes: list[Coordinate]
    _fits_logo: bool

    def __init__(self, dim: Dimension,
                 area: AreaLogo | None = None) -> None:
        """Initializes the board with all walls set and optionally
        stamps a logo.

        Creates a full-walled grid of the given dimensions. If an AreaLogo
        is provided and fits within the board, it is centered and its active
        cells are blocked so the maze generator avoids them.

        Args:
            dim: Dimensions of the board (width x height in cells).
            area: Optional logo pattern to stamp at the center of the board.
        """
        def __fits_logo(dimension: Dimension, area: AreaLogo) -> bool:
            """Checks if the logo fits within the board with at least
            1 cell margin."""
            return dimension.width >= area.dimension.width + 2 and \
                dimension.height >= area.dimension.height + 2

        def __init_logo(dimension: Dimension,
                        area: AreaLogo) -> Coordinate:
            """Computes the top-left coordinate to center the logo
            on the board."""
            return Coordinate(int(dimension.width/2) -
                              int(area.dimension.width/2),
                              int(dimension.height/2) -
                              int(area.dimension.height/2)
                              )
        self._blocked_boxes = []
        self._dimension = dim
        self._grid = [[Box(Direction.ALL_WALLS)
                      for _ in range(self._dimension.width)]
                      for _ in range(self._dimension.height)]
        self._fits_logo = True
        if area is not None:
            if __fits_logo(self._dimension, area):
                ini = __init_logo(dim, area)
                for y in range(0, area.dimension.height):
                    for x in range(0, area.dimension.width):
                        if area.pattern[y][x]:
                            self._grid[ini.y + y][ini.x + x].block()
                            self._blocked_boxes.append(
                                Coordinate(ini.x + x, ini.y + y))
            else:
                self._fits_logo = False
        return

    @property
    def dimension(self) -> Dimension:
        """Returns the dimensions of the board."""
        return self._dimension

    @property
    def blocked_boxes(self) -> list[Coordinate]:
        """Returns the list of coordinates blocked by the logo."""
        return self._blocked_boxes

    @property
    def fits_logo(self) -> bool:
        """ Retunrs True if the logo fits within the board, False otherwise."""
        return self._fits_logo

    def get_box(self, coord: Coordinate) -> Box:
        """Returns the Box at the given coordinate.

        Args:
            coord: The (x, y) coordinate of the cell to retrieve.

        Returns:
            The Box object at the specified position.
        """
        return self._grid[coord.y][coord.x]
