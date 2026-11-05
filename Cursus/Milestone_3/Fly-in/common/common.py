from enum import Enum


class ZoneType(Enum):
    NORMAL = 1
    BLOCKED = 2
    RESTRICTED = 3
    PRIORITY = 4

    @staticmethod
    def get_zone_type(zone: str) -> int:
        """ Returns the zone_type enum value based on the string input.
            Args:
                zone: string with de zone_type.
            Returns:
                The enum value or -1 if the string don't
                math any defined zone_type.
        """
        if zone.upper() in ZoneType.__members__:
            return ZoneType[zone.upper()].value
        return -1


class Colour(Enum):
    RED = 1
    GREEN = 2
    YELLOW = 3
    BLUE = 4
    GRAY = 5

    @staticmethod
    def get_colour(colour: str) -> int:
        """ Returns the colour enum value based on the string input.
            Args:
                colour: string with de color name.
            Returns:
                The enum value or -1 if the string don't
                math any defined colour.
        """
        if colour.upper() in Colour.__members__:
            return Colour[colour.upper()].value
        return -1


class Coordinate:
    _x:  int
    _y: int

    def __init__(self, x: int, y: int) -> None:
        self._x = x
        self._y = y

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
