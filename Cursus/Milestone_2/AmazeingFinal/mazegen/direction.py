class Direction:
    """Represents maze directions as bitmask constants.

    Each direction is a power of 2 to allow bitwise combinations.
    For example, NORTH | EAST = 3 means both walls are active.

    Attributes:
        NONE: No direction.
        NORTH: Top wall, bitmask 0001.
        EAST: Right wall, bitmask 0010.
        SOUTH: Bottom wall, bitmask 0100.
        WEST: Left wall, bitmask 1000.
        ALL_WALLS: All four walls active, bitmask 1111.
        TRANSF: Maps each bitmask to its single-character string label.
    """

    NONE = 0
    NORTH = 1   # bin 0001
    EAST = 2    # bin 0010
    SOUTH = 4   # bin 0100
    WEST = 8    # bin 1000
    ALL_WALLS = NORTH | EAST | SOUTH | WEST     # bin 1111
    TRANSF = {1: "N", 2: "E", 4: "S", 8: "W"}

    @staticmethod
    def reverse(dir: int) -> int:
        """Returns the opposite direction of the given one.

        Args:
            dir: A Direction constant (NORTH, SOUTH, EAST or WEST).

        Returns:
            The opposite Direction constant, or NONE if not recognized.
        """
        match dir:
            case Direction.NORTH:
                return Direction.SOUTH
            case Direction.SOUTH:
                return Direction.NORTH
            case Direction.EAST:
                return Direction.WEST
            case Direction.WEST:
                return Direction.EAST
            case _:
                return Direction.NONE

    @staticmethod
    def reverse_path(lst: list[int]) -> list[int]:
        """Reverses a path by inverting each direction and flipping the order.

        Args:
            lst: List of Direction constants representing a path.

        Returns:
            New list with each direction reversed and the order flipped.
        """
        return [Direction.reverse(item) for item in lst][::-1]


class Offset:
    """Maps each direction to its (dx, dy) displacement in the grid.

    Used to calculate the coordinates of a neighboring cell given
    a direction. For example, moving NORTH from (3, 4) gives (3, 3).

    Attributes:
        offsets: Dictionary mapping Direction constants to (dx, dy) tuples.
    """

    offsets = {
        Direction.NORTH: (0, -1),
        Direction.SOUTH: (0, 1),
        Direction.EAST:  (1, 0),
        Direction.WEST:  (-1, 0),
    }
