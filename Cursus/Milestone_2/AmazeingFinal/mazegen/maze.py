import random
from collections import deque
from .coordinate import Coordinate
from .dimension import Dimension
from .box import Box
from .areaLogo import AreaLogo
from .direction import (Direction, Offset)
from .board import Board
from .exceptions import (MazeEntryError,
                         MazeExitError, MazeDimensionError,
                         MazeExportError)


class Maze:
    """Generates and stores a maze using a depth-first search algorithm.

    Supports perfect mazes (single solution) and imperfect mazes
    (multiple paths). Optionally stamps a logo pattern into the grid
    and computes the shortest solution path via BFS.

    Attributes:
        _entry: Starting coordinate of the maze.
        _exit: Ending coordinate of the maze.
        _dimension: Width and height of the maze in cells.
        _perfect: Whether the maze has exactly one solution.
        _board: The grid of Box cells with wall configuration.
        _shortest_sol: Sequence of Direction constants forming
            the shortest path.
        _creation_path: Ordered list of (Coordinate, Direction)
            steps taken during generation.
    """

    _entry: Coordinate
    _exit: Coordinate
    _dimension: Dimension
    _perfect: bool
    _board: Board
    _shortest_sol: list[int]
    _creation_path: list[tuple[Coordinate, int]]

    ##########################################
    # Algoritmo DFS para crear el laberinto.
    ##########################################
    def __chose_random_wall(self) -> int:
        """Returns a random direction constant.

        Returns:
            One of NORTH, EAST, SOUTH, or WEST chosen at random.
        """
        return random.choice([Direction.NORTH, Direction.EAST,
                              Direction.SOUTH, Direction.WEST])

    def __inside_board(self, coord: Coordinate) -> bool:
        """Checks whether a coordinate lies within the board boundaries.

        Args:
            coord: The coordinate to validate.

        Returns:
            True if the coordinate is inside the board, False otherwise.
        """
        return coord.y >= 0 and coord.y < self._dimension.height \
            and coord.x >= 0 and coord.x < self._dimension.width

    def __init__(self, dim: Dimension, entry: Coordinate,
                 exit: Coordinate,
                 seed: int | float | str | bytes | bytearray,
                 perfect: bool = True,
                 logo: AreaLogo | None = None) -> None:
        """Initializes and generates a maze with the given parameters.

        Validates input, builds the board, optionally seeds the random
        generator, runs DFS generation, and computes the shortest solution.

        Args:
            dim: Dimensions of the maze (width x height in cells).
            entry: Starting coordinate for the maze and DFS generation.
            exit: Target coordinate representing the maze exit.
            perfect: If True, generates a perfect maze with one solution.
                     If False, adds extra paths for multiple routes.
            seed: Optional seed for reproducible random generation.
            logo: Optional logo pattern to stamp at the center of the board.

        Raises:
            MazeDimensionError: If the board is too small to generate a maze.
            MazeEntryError: If the entry is outside the board or
                overlaps the logo.
            MazeExitError: If the exit is outside the board or
                overlaps the logo.
        """

        def __find_shortest_path(start: Coordinate,
                                 exit: Coordinate) -> list[int]:
            """Finds the shortest path from start to exit using BFS.

            Traverses the maze grid respecting wall configurations and
            marks each cell on the solution path.

            Args:
                start: The coordinate to begin the search from.
                exit: The target coordinate to reach.

            Returns:
                List of Direction constants representing the shortest path,
                or an empty list if no path exists.
            """
            queue: deque[Coordinate] = deque([start])
            visited: set[Coordinate] = {start}
            found: bool = False
            current: Coordinate
            neighbor: Coordinate
            parents: dict[Coordinate, int] = {}
            solution: list[int] = []
            dir_taken: int

            while queue:
                current = queue.popleft()
                if current == exit:
                    found = True
                    break
                for direction in [Direction.NORTH, Direction.EAST,
                                  Direction.SOUTH, Direction.WEST]:
                    neighbor = current.add_offset(Offset.offsets[direction])
                    if self.__inside_board(neighbor):
                        if neighbor not in visited and \
                               not self._board.get_box(neighbor).is_blocked():
                            if self._board.get_box(current).get_walls() \
                                   & direction == 0:
                                visited.add(neighbor)
                                parents[neighbor] = direction
                                queue.append(neighbor)

            if found:
                current = exit
                while current != start:
                    dir_taken = parents[current]
                    solution.append(dir_taken)
                    dx, dy = Offset.offsets[dir_taken]
                    current = current.add_offset((-dx, -dy))
                    if current != exit:
                        self._board.get_box(current).set_as_path()

                solution.reverse()
            return solution

        def __room_empty(left_up: Coordinate, dim: Dimension) -> bool:
            """Checks whether all walls within a rectangular region are open.

            Args:
                left_up: Top-left coordinate of the region.
                dim: Dimensions of the region to check.

            Returns:
                True if no internal EAST or SOUTH walls are present,
                    False otherwise.
            """
            current: Coordinate
            current_box: Box

            for y in range(dim.height):
                for x in range(dim.width):
                    current = Coordinate(left_up.x + x, left_up.y + y)
                    current_box = self.board.get_box(current)
                    if x < dim.width - 1:
                        if (current_box.get_walls() & Direction.EAST) != 0:
                            return False
                    if y < dim.height - 1:
                        if (current_box.get_walls() & Direction.SOUTH) != 0:
                            return False
            return True

        def __check_isolated(coord: Coordinate, dim: Dimension) -> bool:
            """Checks whether a coordinate is part of an isolated open region.

            Scans all rectangular regions of the given size that include
            the coordinate and checks if any are fully open (no internal walls)

            Args:
                coord: The coordinate to check.
                dim: Size of the region to scan.

            Returns:
                True if the coordinate belongs to an isolated open region.
            """
            left_up: Coordinate

            for y in range(dim.height):
                for x in range(dim.width):
                    left_up = coord.add_offset((-x, -y))
                    if self.__inside_board(left_up) and \
                       self.__inside_board(left_up.add_offset(
                           (dim.width - 1, dim.height - 1))):
                        if __room_empty(left_up, dim):
                            return True
            return False

        def __add_alternate_paths(creation_path: list[tuple[Coordinate,
                                                            int]],
                                  ptc_down_walls: float) -> None:
            """Removes a percentage of walls to create an imperfect maze.

            Randomly selects cells and tears down walls between neighbors,
            skipping removals that would create isolated open regions.

            Args:
                creation_path: List to append successful wall removals to.
                ptc_down_walls: Fraction of valid cells
                    whose walls to remove (0.0 to 1.0).
            """
            valid_cells: list[Coordinate]
            w_to_down: int
            w_downded: int
            attempts: int
            current: Coordinate
            next: Coordinate
            movement: int
            wall: int

            valid_cells = [
                candidate
                for y in range(self._board.dimension.height)
                for x in range(self._board.dimension.width)
                if (not (candidate := Coordinate(x, y)) and False)
                or not self._board.get_box(candidate).is_blocked()
            ]
            w_to_down = int(len(valid_cells) * ptc_down_walls)
            attempts = 0
            w_downded = 0
            while w_downded < w_to_down and attempts <= w_to_down * 10:
                current = random.choice(valid_cells)
                movement = self.__chose_random_wall()
                next = current.add_offset(Offset.offsets[movement])
                if self.__inside_board(next) and \
                   not self._board.get_box(next).is_blocked():
                    if self._board.get_box(current).get_walls() & \
                       movement != 0:
                        wall = __up_down_wall(current, next, 0)
                        if not __check_isolated(current, Dimension(3, 3)):
                            creation_path.append((current, wall))
                            w_downded += 1
                        else:
                            __up_down_wall(current, next, 1)

        def __up_down_wall(current: Coordinate,
                           next: Coordinate,
                           up: int = 0) -> int:
            """Opens or closes the wall between two adjacent cells.

            Args:
                current: The cell whose wall is being modified.
                next: The neighboring cell on the other side of the wall.
                up: If 0, removes the wall (opens passage).
                    If 1, restores the wall (closes passage).

            Returns:
                The Direction constant of the wall modified
                    on the current cell.
            """
            movements: dict[tuple[int, int], tuple[int, int]]
            wall_current: int
            wall_next: int
            current_box: Box
            next_box: Box

            movements = {(-1, 0): (Direction.NORTH, Direction.SOUTH),
                         (1, 0):  (Direction.SOUTH, Direction.NORTH),
                         (0, 1):  (Direction.EAST,  Direction.WEST),
                         (0, -1): (Direction.WEST,  Direction.EAST)}

            wall_current, wall_next = movements[(next.y - current.y,
                                                 next.x - current.x)]
            current_box = self._board.get_box(current)
            next_box = self._board.get_box(next)
            if up == 0:
                current_box.set_walls(current_box.get_walls() & ~wall_current)
                next_box.set_walls(next_box.get_walls() & ~wall_next)
            else:
                current_box.set_walls(current_box.get_walls() | wall_current)
                next_box.set_walls(next_box.get_walls() | wall_next)
            return wall_current

        def __get_unvisited_neighbors(current: Coordinate,
                                      visited: set[Coordinate]) \
                -> list[Coordinate]:
            """Returns all unvisited, unblocked neighbors of a cell.

            Args:
                current: The cell whose neighbors to inspect.
                visited: Set of already visited coordinates.

            Returns:
                List of neighboring coordinates that are inside the board,
                not yet visited, and not blocked.
            """
            unvisited: list[Coordinate] = []
            candidate: Coordinate

            for dir in [Direction.NORTH, Direction.EAST,
                        Direction.SOUTH, Direction.WEST]:
                (dx, dy) = Offset.offsets[dir]
                candidate = Coordinate(current.x + dx, current.y + dy)
                if self.__inside_board(candidate) \
                   and candidate not in visited \
                   and not self._board.get_box(candidate).is_blocked():
                    unvisited.append(candidate)
            return unvisited

        def __number_of_walls(box: Box) -> int:
            """
            Counts the number of walls present in a Box.

            Args:
                box: The Box instance to count walls for.

            Returns:
                The number of walls present in the Box.
            """
            walls: int
            num_walls: int = 0

            walls = box.get_walls()
            if walls & Direction.NORTH:
                num_walls += 1
            if walls & Direction.EAST:
                num_walls += 1
            if walls & Direction.SOUTH:
                num_walls += 1
            if walls & Direction.WEST:
                num_walls += 1
            return num_walls

        def __walls_candidates_to_down(coor: Coordinate) -> list[int]:
            """
            Returns a list of wall directions that can be removed
            from the given coordinate without creating isolated regions.

            Args:
                coor: The coordinate of the cell to inspect.

            Returns:
                List of Direction constants representing walls that can be
                safely removed.
            """
            walls: int
            candidate: list[int] = []

            walls = self._board.get_box(coor).get_walls()
            if walls & Direction.NORTH and\
               not coor.y == 0 and\
               not self._board.get_box(Coordinate(coor.x,
                                                  coor.y - 1)).is_blocked():
                candidate.append(Direction.NORTH)
            if walls & Direction.EAST and\
               not coor.x == self._board.dimension.width - 1 and\
               not self._board.get_box(Coordinate(coor.x + 1,
                                                  coor.y)).is_blocked():
                candidate.append(Direction.EAST)
            if walls & Direction.SOUTH and\
               not coor.y == self._board.dimension.height - 1 and\
               not self._board.get_box(Coordinate(coor.x,
                                                  coor.y + 1)).is_blocked():
                candidate.append(Direction.SOUTH)
            if walls & Direction.WEST and\
               not coor.x == 0 and\
               not self._board.get_box(Coordinate(coor.x - 1,
                                                  coor.y)).is_blocked():
                candidate.append(Direction.WEST)
            return candidate

        def __check_closed_paths(creation_path:
                                 list[tuple[Coordinate, int]]) -> None:
            """
            Iteratively checks all cells in the maze for dead ends (cells
            with 3 or more walls) and removes a wall to create an alternate
            path. Continues until no more dead ends are found.

            Args:
                creation_path: List to append any additional wall removals to.

            """

            candidates_to_down: list[int]
            current: Coordinate
            next: Coordinate
            wall_down: int
            walls_downed: bool = True

            while walls_downed:
                walls_downed = False
                for row in range(0, self._board.dimension.height):
                    for col in range(0, self._board.dimension.width):
                        current = Coordinate(col, row)
                        if not self._board.get_box(current).is_blocked() and \
                                __number_of_walls(
                                    self._board.get_box(current)) >= 3:
                            # Check walls to down.
                            candidates_to_down = __walls_candidates_to_down(
                                                    current)
                            # If there are any wall to down,
                            # choice one randomly.
                            if len(candidates_to_down) > 0:
                                next = current.add_offset(
                                        Offset.offsets[
                                            random.choice(candidates_to_down)])
                                wall_down = __up_down_wall(current, next, 0)
                                creation_path.append((current, wall_down))
                                walls_downed = True

        def __create_maze(start: Coordinate) \
                -> list[tuple[Coordinate, int]]:
            """Generates the maze using iterative depth-first search.

            Carves passages by removing walls between cells until all
            reachable cells have been visited. If the maze is imperfect,
            adds extra passages afterward.

            Args:
                start: The coordinate to begin generation from.

            Returns:
                Ordered list of (Coordinate, Direction) pairs recording
                each wall removal during generation.
            """
            pile: list[Coordinate] = []
            current: Coordinate = start
            visited: set[Coordinate] = set()
            next: Coordinate
            creation_path: list[tuple[Coordinate, int]] = []

            pile.append(current)
            visited.add(current)
            while len(pile) > 0:
                current = pile[-1]
                free_neighbors = __get_unvisited_neighbors(current, visited)
                if len(free_neighbors) > 0:
                    next = random.choice(free_neighbors)
                    creation_path.append((current,
                                         __up_down_wall(current, next, 0)))
                    visited.add(next)
                    pile.append(next)
                else:
                    pile.pop()
            if not self._perfect:
                __add_alternate_paths(creation_path, 0.1)
                __check_closed_paths(creation_path)
            return creation_path

        def __check_input_values() -> None:
            """Validates board dimensions, entry, and exit coordinates.

            Raises:
                MazeDimensionError: If the board has fewer than 2 cells.
                MazeExitError: If the exit is outside the board.
                MazeEntryError: If the entry is outside the board.
            """
            if self._dimension.width * self._dimension.height < 2:
                raise MazeDimensionError("Dimension isn't big \
                                         enough to create Maze.")
            if not self.__inside_board(self._exit):
                raise MazeExitError("Exit coodinates outside limits.")
            if not self.__inside_board(self._entry):
                raise MazeEntryError("Entry coodinates outside limits.")

        def __check_entry_exit() -> None:
            """Checks that entry and exit do not overlap the logo.

            Raises:
                MazeEntryError: If the entry cell is blocked by the logo.
                MazeExitError: If the exit cell is blocked by the logo.
            """
            if self._board.get_box(self._entry).is_blocked():
                raise MazeEntryError("Entry coodinates overlap LOGO")
            if self._board.get_box(self._exit).is_blocked():
                raise MazeExitError("Exit coodinates overlap LOGO")

        self._dimension = dim
        self._entry = entry
        self._exit = exit
        self._perfect = perfect

        __check_input_values()
        self._board = Board(dim, logo)
        __check_entry_exit()
        random.seed(seed)
        self._creation_path = __create_maze(entry)
        self._shortest_sol = __find_shortest_path(entry, exit)

    def export(self, filename: str) -> None:
        """Exports the maze to a text file.

        Writes the wall configuration of each cell as a hex character grid,
        followed by the entry and exit coordinates and
        the shortest solution path.

        Args:
            filename: Path to the output file.

        Raises:
            MazeExportError: If the file cannot be written.
        """
        base: str = "0123456789ABCDEF"
        output: str

        try:
            with open(filename, "w") as file:
                for row in range(self._board.dimension.height):
                    output = "".join([base[self._board.get_box(
                        Coordinate(col, row)).get_walls()]
                        for col in range(self._board.dimension.width)]) + "\n"
                    file.write(output)
                file.write("\n")
                file.write(f"{self._entry.x}, {self._entry.y}\n")
                file.write(f"{self._exit.x}, {self._exit.y}\n")
                output = "".join([Direction.TRANSF[dir]
                                  for dir in self._shortest_sol]) + "\n"
                file.write(output)
        except Exception as e:
            raise MazeExportError(f"{e}")

    def export_blocked_boxex(self, filename: str) -> None:
        """Exports the coordinates of all blocked cells to a text file.

        Args:
            filename: Path to the output file.

        Raises:
            MazeExportError: If the file cannot be written.
        """
        try:
            with open(filename, "w") as file:
                for coor in self._board.blocked_boxes:
                    file.write(f"({coor.x}, {coor.y})\n")
        except Exception as e:
            raise MazeExportError(f"{e}")

    def export_creation_path(self, filename: str) -> None:
        """Exports the DFS creation path to a text file.

        Each line contains the coordinate and direction of a wall removal
        in the order it occurred during generation.

        Args:
            filename: Path to the output file.

        Raises:
            MazeExportError: If the file cannot be written.
        """
        try:
            with open(filename, "w") as file:
                for coor, direction in self._creation_path:
                    file.write(f"(({coor.x}, {coor.y}), {direction})\n")
        except Exception as e:
            raise MazeExportError(f"{e}")

    @property
    def shortest_sol(self) -> list[int]:
        """Returns the shortest solution as a list of Direction constants."""
        return self._shortest_sol

    @property
    def creation_path(self) -> list[tuple[Coordinate, int]]:
        """Returns the ordered list of wall removals from DFS generation."""
        return self._creation_path

    @property
    def board(self) -> Board:
        """Returns the maze board containing all cell data."""
        return self._board

    @property
    def dimension(self) -> Dimension:
        """Returns the dimensions of the maze."""
        return self._dimension

    @property
    def entry(self) -> Coordinate:
        """Returns the entry coordinate of the maze."""
        return self._entry

    @property
    def exit(self) -> Coordinate:
        """Returns the exit coordinate of the maze."""
        return self._exit

    @property
    def fits_logo(self) -> bool:
        return self.board.fits_logo
