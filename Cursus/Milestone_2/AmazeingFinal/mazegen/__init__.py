"""Maze generation library providing the core maze building blocks.

Exposes the Maze generator, Dimension and Coordinate value types,
and the AreaLogo pattern used to stamp a logo into the maze grid.
"""

from .maze import Maze
from .dimension import Dimension
from .coordinate import Coordinate
from .areaLogo import AreaLogo
from .exceptions import ErrorMaze

__all__ = ["Maze", "Dimension", "Coordinate", "AreaLogo", "ErrorMaze"]
