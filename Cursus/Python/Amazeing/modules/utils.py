# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  utils.py                                          :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: igarciab <igarciab@student.42.fr>         +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/06/08 23:52:03 by igarciab        #+#    #+#               #
#  Updated: 2026/06/09 01:04:16 by igarciab        ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Coordinate:
    _x: int
    _y: int

    def __init__(self, y: int = 0, x: int = 0) -> None:
        self._x = x
        self._y = y

#    def equal(self, coord: "Coordinate") -> bool:
#        return self._x == coord.x and self._y == coord.y

    def __eq__(self, otro: object) -> bool:
        if not isinstance(otro, Coordinate):
            return False
        return self.x == otro.x and self.y == otro.y

    @property
    def x(self) -> int:
        return self._x

    @x.setter
    def x(self, x: int) -> None:
        self._x = x

    @property
    def y(self) -> int:
        return self._y

    @y.setter
    def y(self, y: int) -> None:
        self._y = y


class Dimension:
    _width: int
    _height: int

    def __init__(self, height: int = 0, width: int = 0) -> None:
        self._width = width
        self._height = height

    @property
    def height(self) -> int:
        return self._height

    @height.setter
    def height(self, height: int) -> None:
        self._height = height

    @property
    def width(self) -> int:
        return self._width

    @width.setter
    def width(self, width: int) -> None:
        self._width = width


class Direction:
    NONE = 0
    NORTH = 8   # bin 1000
    EAST = 4    # bin 0100
    SOUTH = 2   # bin 0010
    WEST = 1    # bin 0001
    ALL_WALLS = NORTH | EAST | SOUTH | WEST     # bin 11111


class Step:
    _coor: Coordinate
    _mov: int

    def __init__(self, coor: Coordinate, mov: int) -> None:
        self._coor = coor
        self._mov = mov

    @property
    def coord(self) -> Coordinate:
        return self._coor

    @property
    def movement(self) -> int:
        return self._mov


class Box:
    _walls: int
    _visited: bool
    _blocked: bool
    _is_path: bool

    def __init__(self, walls: int, visited: bool = False,
                 blocked: bool = False, is_path: bool = False) -> None:
        self._walls = walls
        self._visited = visited
        self._blocked = blocked
        self._is_path = is_path

    def block(self) -> None:
        self._blocked = True

    def unblock(self) -> None:
        self._blocked = False

    def is_blocked(self) -> bool:
        return self._blocked

    def set_as_visited(self) -> None:
        self._visited = True

    def set_as_unvisited(self) -> None:
        self._visited = False

    def is_visited(self) -> bool:
        return self._visited

    def set_as_path(self) -> None:
        self._is_path = True

    def set_as_no_path(self) -> None:
        self._is_path = False

    def is_path(self) -> bool:
        return self._is_path

    def set_walls(self, walls: int) -> None:
        self._walls = walls

    def get_walls(self) -> int:
        return self._walls
