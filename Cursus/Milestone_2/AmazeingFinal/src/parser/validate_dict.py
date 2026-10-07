#!/usr/bin/env python3

from typing import Any
from .exceptions import (
    MissingMandatoryKeyError,
    InvalidValueError,
    InvalidMazeBoundsError
)


def validate_required_keys(config: dict[str, str]) -> None:
    """Checks that all mandatory keys are present in the configuration.

    Args:
        config: Raw configuration dictionary parsed from the config file.

    Raises:
        MissingMandatoryKeyError: If any required key is absent.
    """
    required_keys = ["WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE",
                     "PERFECT"]
    for key in required_keys:
        if key not in config:
            raise MissingMandatoryKeyError(f"Missing mandatory key: {key}")


def parse_dimensions(config: dict[str, str]) -> tuple[int, int]:
    """Parses and validates the WIDTH and HEIGHT values from the configuration.

    Args:
        config: Raw configuration dictionary parsed from the config file.

    Returns:
        A tuple of (width, height) as integers.

    Raises:
        InvalidValueError: If WIDTH or HEIGHT are not valid integers.
        InvalidMazeBoundsError: If WIDTH or HEIGHT are not greater than 1.
    """
    try:
        width = int(config["WIDTH"])
        height = int(config["HEIGHT"])
    except ValueError:
        raise InvalidValueError("WIDTH and HEIGHT must be integers.")

    if width <= 1:
        raise InvalidMazeBoundsError("WIDTH should be higher than 1.")
    if height <= 1:
        raise InvalidMazeBoundsError("HEIGHT should be higher than 1.")
    return width, height


def parse_point(point: str, config: dict[str, str], width: int, height: int
                ) -> tuple[int, int]:
    """Parses and validates a coordinate point from the configuration.

    Args:
        point: The configuration key to parse (e.g. "ENTRY" or "EXIT").
        config: Raw configuration dictionary parsed from the config file.
        width: The maze width used to validate the x boundary.
        height: The maze height used to validate the y boundary.

    Returns:
        A tuple of (x, y) as integers.

    Raises:
        InvalidValueError: If the format is not 'x,y' or values
        are not integers.
        InvalidMazeBoundsError: If the coordinate falls
        outside the maze bounds.
    """
    coords = config[point].split(",")

    if len(coords) != 2:
        raise InvalidValueError(f"{point} should have the format 'x,y'.")

    try:
        x, y = int(coords[0]), int(coords[1])
    except ValueError:
        raise InvalidValueError(f"{point} coordinates must be integers.")

    if not (0 <= x < width) or not (0 <= y < height):
        raise InvalidMazeBoundsError(
            f"{point} ({x},{y}) outside the limits: "
            f"x must be in [0, {width - 1}] and y in [0, {height - 1}]"
        )

    return x, y


def parse_perfect(config: dict[str, str]) -> bool:
    """Parses the PERFECT flag from the configuration.

    Args:
        config: Raw configuration dictionary parsed from the config file.

    Returns:
        True if the maze should be perfect, False otherwise.

    Raises:
        InvalidValueError: If the value is not one of 'true',
        '1', 'false', or '0'.
    """
    value = config["PERFECT"].lower()

    if value in ["true", "1"]:
        return True
    if value in ["false", "0"]:
        return False

    raise InvalidValueError("PERFECT should be 'True' or 'False'.")


def parse_seed(config: dict[str, str]) -> int | None:
    """Parses the optional SEED value from the configuration.

    Args:
        config: Raw configuration dictionary parsed from the config file.

    Returns:
        The seed as an integer, or None if not provided.

    Raises:
        InvalidValueError: If SEED is present but not a valid integer.
    """
    seed_value = config.get("SEED")
    if seed_value is not None:
        try:
            return int(seed_value)
        except ValueError:
            raise InvalidValueError("SEED must be an integer.")
    return None


def validate_config(config: dict[str, str]) -> dict[str, Any]:
    """Validates the full configuration dictionary and returns typed values.

    Runs all individual validation steps in order and assembles the
    final configuration ready for maze construction.

    Args:
        config: Raw configuration dictionary parsed from the config file.

    Returns:
        A dictionary with validated and typed configuration values.

    Raises:
        MissingMandatoryKeyError: If any required key is absent.
        InvalidValueError: If any value has an unexpected type or format.
        InvalidMazeBoundsError: If any coordinate or dimension is
        out of bounds,
            or if ENTRY and EXIT are the same coordinate.
    """
    validate_required_keys(config)

    validated: dict[str, Any] = {}

    width, height = parse_dimensions(config)
    validated["WIDTH"] = width
    validated["HEIGHT"] = height

    validated["ENTRY"] = parse_point("ENTRY", config, width, height)
    validated["EXIT"] = parse_point("EXIT", config, width, height)

    if validated["ENTRY"] == validated["EXIT"]:
        raise InvalidMazeBoundsError("ENTRY and EXIT should be different.")

    validated["PERFECT"] = parse_perfect(config)
    validated["OUTPUT_FILE"] = config["OUTPUT_FILE"]
    validated["SEED"] = parse_seed(config)

    return validated
