#!/usr/bin/env python3

# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  a_maze_ing.py                                     :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/08 11:27:45 by igarciab        #+#    #+#               #
#  Updated: 2026/06/09 01:11:51 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

import random
from typing import Optional
from modules.utils import Coordinate
from modules.utils import Dimension
from modules.utils import Direction
from modules.utils import Step
from modules.utils import Box


class AreaLogo:
    _dimension: Dimension
    _pattern: list[list[bool]]

    def __init__(self) -> None:
        self._dimension = Dimension(5, 7)
        self._pattern = [[True, False, False, False, True, True, True],
                         [True, False, False, False, False, False, True],
                         [True, True, True, False, True, True, True],
                         [False, False, True, False, True, False, False],
                         [False, False, True, False, True, True, True]]

    @property
    def dimension(self) -> Dimension:
        return self._dimension

    @property
    def pattern(self) -> list[list[bool]]:
        return self._pattern


class Board:
    _entry: Coordinate
    _exit: Coordinate
    _dimension: Dimension
    _squares: list[list[Box]]
    _solution: list[Step]

    def __fits_logo(self, area: AreaLogo) -> bool:
        return self._dimension.width >= area.dimension.width + 2 and\
           self._dimension.height >= area.dimension.height + 2

    def __init_logo(self, area: AreaLogo) -> Coordinate:
        return Coordinate(int(self._dimension.height/2) -
                          int(area.dimension.height/2),
                          int(self._dimension.width/2) -
                          int(area.dimension.width/2))

    def __init_board(self, area: AreaLogo) -> None:
        # Create game board with walls in all squares
        # and any of them blocked.
        self._squares = [[Box(Direction.ALL_WALLS)
                         for _ in range(self._dimension.width)]
                         for _ in range(self._dimension.height)]
        # Fills with LOGO.
        if self.__fits_logo(area):
            ini = self.__init_logo(area)
            for y in range(0, area.dimension.height):
                for x in range(0, area.dimension.width):
                    if area.pattern[y][x]:
                        self._squares[ini.y + y][ini.x + x].block()
        else:
            print("No enough space to paint logo.")

    def __get_random_direction(self,
                               pos: Coordinate) -> Optional[int]:
        candidates: list[int] = []
        # Check North
        if pos.y - 1 >= 0:
            if not self._squares[pos.y - 1][pos.x].is_visited() and \
               not self._squares[pos.y - 1][pos.x].is_blocked() and \
               not self._squares[pos.y - 1][pos.x].is_path():
                candidates.append(Direction.NORTH)
        # Check East
        if pos.x + 1 < self._dimension.width:
            if not self._squares[pos.y][pos.x + 1].is_visited() and \
               not self._squares[pos.y][pos.x + 1].is_blocked() and \
               not self._squares[pos.y][pos.x + 1].is_path():
                candidates.append(Direction.EAST)
        # Check South
        if pos.y + 1 < self._dimension.height:
            if not self._squares[pos.y + 1][pos.x].is_visited() and \
               not self._squares[pos.y + 1][pos.x].is_blocked() and \
               not self._squares[pos.y + 1][pos.x].is_path():
                candidates.append(Direction.SOUTH)
        # Check West
        if pos.x - 1 >= 0:
            if not self._squares[pos.y][pos.x - 1].is_visited() and \
               not self._squares[pos.y][pos.x - 1].is_blocked() and \
               not self._squares[pos.y][pos.x - 1].is_path():
                candidates.append(Direction.WEST)
        if candidates:
            return random.choice(candidates)
        return None

    def __down_walls(self, step: Step) -> None:
        current: Box
        neighbor: Box

        current = self._squares[step.coord.y][step.coord.x]
        match step.movement:
            case Direction.NORTH:
                neighbor = self._squares[step.coord.y - 1][step.coord.x]
                current.set_walls(current.get_walls()
                                  & ~Direction.NORTH)
                neighbor.set_walls(neighbor.get_walls()
                                   & ~Direction.SOUTH)
            case Direction.EAST:
                neighbor = self._squares[step.coord.y][step.coord.x + 1]
                current.set_walls(current.get_walls() &
                                  ~Direction.EAST)
                neighbor.set_walls(neighbor.get_walls() &
                                   ~Direction.WEST)
            case Direction.SOUTH:
                neighbor = self._squares[step.coord.y + 1][step.coord.x]
                current.set_walls(current.get_walls() &
                                  ~Direction.SOUTH)
                neighbor.set_walls(neighbor.get_walls() &
                                   ~Direction.NORTH)
            case Direction.WEST:
                neighbor = self._squares[step.coord.y][step.coord.x - 1]
                current.set_walls(current.get_walls() &
                                  ~Direction.WEST)
                neighbor.set_walls(neighbor.get_walls() &
                                   ~Direction.EAST)

    def __build_walls(self, step: Step) -> None:
        current: Box
        neighbor: Box

        current = self._squares[step.coord.y][step.coord.x]
        match step.movement:
            case Direction.NORTH:
                neighbor = self._squares[step.coord.y - 1][step.coord.x]
                current.set_walls(current.get_walls()
                                  | Direction.NORTH)
                neighbor.set_walls(neighbor.get_walls()
                                   | Direction.SOUTH)
            case Direction.EAST:
                neighbor = self._squares[step.coord.y][step.coord.x + 1]
                current.set_walls(current.get_walls() |
                                  Direction.EAST)
                neighbor.set_walls(neighbor.get_walls() |
                                   Direction.WEST)
            case Direction.SOUTH:
                neighbor = self._squares[step.coord.y + 1][step.coord.x]
                current.set_walls(current.get_walls() |
                                  Direction.SOUTH)
                neighbor.set_walls(neighbor.get_walls() |
                                   Direction.NORTH)
            case Direction.WEST:
                neighbor = self._squares[step.coord.y][step.coord.x - 1]
                current.set_walls(current.get_walls() |
                                  Direction.WEST)
                neighbor.set_walls(neighbor.get_walls() |
                                   Direction.EAST)

    def __get_neighbor(self, coord: Coordinate, dir: int) -> Coordinate:
        coor: Coordinate

        match dir:
            case Direction.NORTH:
                coor = Coordinate(coord.y - 1, coord.x)
            case Direction.EAST:
                coor = Coordinate(coord.y, coord.x + 1)
            case Direction.SOUTH:
                coor = Coordinate(coord.y + 1, coord.x)
            case Direction.WEST:
                coor = Coordinate(coord.y, coord.x - 1)
        return coor

    def __create_solution(self) -> None:
        neighbor: Coordinate
        dir: Optional[int]
        step: Step

        self._solution.append(Step(self._entry, Direction.NONE))
        self._squares[self._entry.y][self._entry.x].set_as_visited()
        self._squares[self._entry.y][self._entry.x].set_as_path()
        while not self._solution[-1].coord == self._exit:
            dir = self.__get_random_direction(self._solution[-1].coord)
            if dir:
                # Found a valid direction
                neighbor = self.__get_neighbor(self._solution[-1].coord, dir)
                # Mark the box as visited and as path
                self._squares[neighbor.y][neighbor.x].set_as_visited()
                self._squares[neighbor.y][neighbor.x].set_as_path()
                # Update last step with dir
                self._solution[-1] = Step(self._solution[-1].coord, dir)
                # Down walls
                self.__down_walls(self._solution[-1])
                # Add neighbor as last step.
                self._solution.append(Step(neighbor, Direction.NONE))
            else:
                # Backtracking
                step = self._solution.pop()
                # Mark de box as NO path
                self._squares[step.coord.y][step.coord.x].set_as_no_path()
                self.__build_walls(self._solution[-1])
                self._solution[-1] = Step(self._solution[-1].coord,
                                          Direction.NONE)
        # Set all boxes as unvisited
        for fila in self._squares:
            for sq in fila:
                sq.set_as_unvisited()

    def __create_rest_board(self) -> None:
        for fila in self._squares:
            for sq in fila:
                sq.set_as_unvisited()

    def __init__(self, dim: Dimension, entry: Coordinate,
                 exit: Coordinate, algorithm: int = 0) -> None:
        self._dimension = dim
        self._entry = entry
        self._exit = exit
        self._solution = []

        self.__init_board(AreaLogo())
        self.__create_solution()
        self.__create_rest_board()

    def print_board(self) -> None:
        box: Box
        walls: int

        for y in range(self._dimension.height):
            linea_superior = ""
            linea_intermedia = ""
            for x in range(self._dimension.width):
                box = self._squares[y][x]
                walls = box.get_walls()
                padding = "   "
                padding = "XXX" if box.is_blocked() else padding
                if Coordinate(y, x) == self._entry:
                    padding = " I "
                elif Coordinate(y, x) == self._exit:
                    padding = " E "
                elif box.is_path():
                    padding = " o "
                if walls & Direction.NORTH:
                    linea_superior += "┼───"
                else:
                    linea_superior += f"┼{padding}"
                if walls & Direction.WEST:
                    linea_intermedia += f"│{padding}"
                else:
                    linea_intermedia += f" {padding}"
            linea_superior += "┼"
            linea_intermedia += "│"
            print(linea_superior)
            print(linea_intermedia)
        print("┼───" * self._dimension.width + "┼")

    def print_solution(self) -> None:
        for step in self._solution:
            print(f"(y ,x) - ({step.coord.y}, {step.coord.x})")


class Maze:
    _seed: int
    _algorithm: int
    _display_mode: int
    _game_board: Board

    def __init__(self, dim: Dimension, entry: Coordinate,
                 exit: Coordinate, seed: int = 0,
                 algorithm: int = 0, display_mode: int = 0) -> None:
        # Generate board
        self._seed = seed
        self._game_board = Board(dim, entry, exit, algorithm)
        self._algorithm = algorithm
        self._display_mode = display_mode
        return

    def print_board(self) -> None:
        self._game_board.print_board()

    def print_solution(self) -> None:
        self._game_board.print_solution()


def main() -> None:
    maze: Maze
    print("Generating board...")
    maze = Maze(Dimension(20, 20), Coordinate(1, 4), Coordinate(18, 17))
    print("Board generated.\n\nSolution:")
    maze.print_solution()
    print("\nBoard\n")
    maze.print_board()


if __name__ == "__main__":
    main()
