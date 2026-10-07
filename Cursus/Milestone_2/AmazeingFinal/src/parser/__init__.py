"""Parser package for reading and validating the maze configuration file.

Exposes the main parsing entry point, filename checker, and base
exception for callers to import directly from src.parser.
"""

from .create_dict import parse_maze_config, check_filename
from .exceptions import ParserError
from .handle_signit import handle_sigint

__all__ = ["parse_maze_config", "check_filename", "ParserError",
           "handle_sigint"]
