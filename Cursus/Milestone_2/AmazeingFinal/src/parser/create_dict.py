#!/usr/bin/env python3

import sys
from typing import Any
from .validate_dict import validate_config
from .exceptions import (
    InvalidArgumentsError,
    ConfigFileNotFoundError,
    ConfigSyntaxError
)


def check_filename() -> str:
    """Validates and returns the configuration filename
    from command-linearguments.

    Expects exactly one argument: the path to the configuration file.

    Returns:
        The filename provided as a command-line argument.

    Raises:
        InvalidArgumentsError: If the number of arguments is not exactly one.
    """
    argc = len(sys.argv) - 1
    if argc != 1:
        raise InvalidArgumentsError()
    filename = sys.argv[1]
    return filename


def read_file(filename: str) -> str:
    """Reads and returns the contents of a configuration file.

    Args:
        filename: Path to the configuration file to read.

    Returns:
        The full contents of the file as a string.

    Raises:
        ConfigFileNotFoundError: If the file does not exist or cannot be read.
    """
    try:
        with open(filename, "r", encoding="utf-8") as file:
            return file.read()
    except (FileNotFoundError, PermissionError):
        raise ConfigFileNotFoundError("Configuration file not found:"
                                      f"'{filename}'")


def transform_file_content(content: str) -> dict[str, str]:
    """Parses raw file content into a key-value configuration dictionary.

    Skips empty lines and comments (lines starting with #).
    Expects each non-empty line to follow the KEY=VALUE format.

    Args:
        content: Raw string content of the configuration file.

    Returns:
        Dictionary mapping configuration keys to their string values.

    Raises:
        ConfigSyntaxError: If a line does not follow the KEY=VALUE format.
    """
    lines = content.splitlines()
    config_dict: dict[str, str] = {}
    for line_num, line in enumerate(lines, 1):
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        if "=" in line:
            key, value = line.split("=", 1)
            config_dict[key.strip()] = value.strip()
        else:
            raise ConfigSyntaxError(
                "Invalid syntax in configuration file on line"
                f"{line_num}: Expected KEY=VALUE format."
            )
    return config_dict


def parse_maze_config() -> dict[str, Any]:
    """Orchestrates parsing of the maze configuration file.

    Reads the filename from command-line arguments, reads the file,
    transforms its content into a raw dictionary, and validates it.

    Returns:
        A validated configuration dictionary with typed values
        ready for maze construction.

    Raises:
        InvalidArgumentsError: If command-line arguments are invalid.
        ConfigFileNotFoundError: If the configuration file cannot be read.
        ConfigSyntaxError: If the file contains malformed lines.
        ParserError: If the configuration values fail validation.
    """
    filename = check_filename()
    content = read_file(filename)
    config_dict = transform_file_content(content)
    return validate_config(config_dict)
