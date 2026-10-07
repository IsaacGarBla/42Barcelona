#!/usr/bin/env python3

from typing import Any
from mazegen import AreaLogo

# ---------------------------------------------------------------------------
# Drawing primitives
# ---------------------------------------------------------------------------


def draw_line(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    x0: int, y0: int, x1: int, y1: int,
    color: int,
) -> None:
    """Draws a line between two pixel coordinates using Bresenham's
    line algorithm.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        x0 (int): Starting X coordinate.
        y0 (int): Starting Y coordinate.
        x1 (int): Ending X coordinate.
        y1 (int): Ending Y coordinate.
        color (int): BGR or RGB color integer.
    """
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    sx = 1 if x0 < x1 else -1
    sy = 1 if y0 < y1 else -1
    err = dx - dy

    while True:
        m.mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color)
        if x0 == x1 and y0 == y1:
            break
        e2 = 2 * err
        if e2 > -dy:
            err -= dy
            x0 += sx
        if e2 < dx:
            err += dx
            y0 += sy


def draw_square(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    x: int, y: int, size: int,
    color: int,
) -> None:
    """Fills a small square to highlight entry, exit, or path cells.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        x (int): Top-left X pixel coordinate.
        y (int): Top-left Y pixel coordinate.
        size (int): Width and height of the square in pixels.
        color (int): BGR or RGB color integer.
    """
    for i in range(x, x + size):
        for j in range(y, y + size):
            m.mlx_pixel_put(mlx_ptr, win_ptr, i, j, color)


def str_color(color: int) -> int:
    """Converts a 0xRRGGBB color code to 0xBBGGRR format for mlx_string_put.

    Args:
        color (int): Color value in 0xRRGGBB format.

    Returns:
        int: Converted color value in 0xBBGGRR format.
    """
    r = (color >> 16) & 0xFF
    g = (color >> 8) & 0xFF
    b = color & 0xFF
    return (b << 16) | (g << 8) | r


# ---------------------------------------------------------------------------
# Maze cell drawing
# ---------------------------------------------------------------------------

def draw_cell_walls(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    row_idx: int, col_idx: int,
    wall_bits: int,
    color: int,
    offset_x: int, offset_y: int, cell_size: int,
) -> None:
    """Draws the walls of a single maze cell based on a 4-bit bitmask.

    Bitmask encoding:
        - bit 0 (1) -> North wall
        - bit 1 (2) -> East wall
        - bit 2 (4) -> South wall
        - bit 3 (8) -> West wall

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        row_idx (int): Row index in the maze grid.
        col_idx (int): Column index in the maze grid.
        wall_bits (int): Integer bitmask representing presence of walls.
        color (int): Color integer for the walls.
        offset_x (int): Horizontal pixel offset for the grid drawing.
        offset_y (int): Vertical pixel offset for the grid drawing.
        cell_size (int): Dimensions of a single cell in pixels.
    """
    x0 = offset_x + col_idx * cell_size
    y0 = offset_y + row_idx * cell_size
    x1 = x0 + cell_size
    y1 = y0 + cell_size

    if wall_bits & 1:
        draw_line(m, mlx_ptr, win_ptr, x0, y0, x1, y0, color)   # North
    if wall_bits & 2:
        draw_line(m, mlx_ptr, win_ptr, x1, y0, x1, y1, color)   # East
    if wall_bits & 4:
        draw_line(m, mlx_ptr, win_ptr, x0, y1, x1, y1, color)   # South
    if wall_bits & 8:
        draw_line(m, mlx_ptr, win_ptr, x0, y0, x0, y1, color)   # West


def draw_maze_walls(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    grid: list[str],
    wall_color: int,
    offset_x: int, offset_y: int, cell_size: int,
) -> None:
    """Iterates over every cell in the grid and draws its walls.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        grid (list[str]): List of hexadecimal strings representing rows.
        wall_color (int): Color integer for the walls.
        offset_x (int): Horizontal pixel offset for the grid drawing.
        offset_y (int): Vertical pixel offset for the grid drawing.
        cell_size (int): Dimensions of a single cell in pixels.
    """
    for row_idx, row in enumerate(grid):
        for col_idx, char in enumerate(row):
            draw_cell_walls(
                m, mlx_ptr, win_ptr,
                row_idx, col_idx,
                int(char, 16),
                wall_color,
                offset_x, offset_y, cell_size,
            )


def draw_solution_path(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    path_str: str,
    entry: tuple[int, int],
    exit_coord: tuple[int, int],
    offset_x: int, offset_y: int, cell_size: int,
    color: int = 0x00FFFFFF,
) -> None:
    """Walks path_str from entry and draws a filled square on each
    intermediate cell.

    Entry and exit cells are excluded from path rendering so their
    markers remain visible.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        path_str (str): Sequence of direction characters ('N', 'S', 'E', 'W').
        entry (tuple[int, int]): Entry cell coordinates (row, col).
        exit_coord (tuple[int, int]): Exit cell coordinates (row, col).
        offset_x (int): Horizontal pixel offset for the grid drawing.
        offset_y (int): Vertical pixel offset for the grid drawing.
        cell_size (int): Dimensions of a single cell in pixels.
        color (int, optional): Color integer for the path markers.
        Defaults to white (0x00FFFFFF).
    """
    curr_y, curr_x = entry
    direction_map = {"N": (-1, 0), "S": (1, 0), "E": (0, 1), "W": (0, -1)}

    for step in path_str:
        dy, dx = direction_map.get(step, (0, 0))
        curr_y += dy
        curr_x += dx

        if (curr_y, curr_x) != exit_coord:
            draw_square(
                m, mlx_ptr, win_ptr,
                offset_x + curr_x * cell_size + 10,
                offset_y + curr_y * cell_size + 10,
                cell_size - 20,
                color,
            )


# ---------------------------------------------------------------------------
# File parsing
# ---------------------------------------------------------------------------

_VALID_PATH_CHARS: frozenset[str] = frozenset("NESW")
_VALID_HEX_CHARS:  frozenset[str] = frozenset("0123456789abcdefABCDEF")


def _parse_coord(raw: str, label: str) -> tuple[int, int]:
    """Parses a coordinate line into a (row, col) tuple.

    Accepts both formats produced by the maze generator:
        - Python tuple syntax: '(0, 0)'  or  '(0,0)'
        - Plain CSV syntax:    '0,0'     or  '0, 0'

    Args:
        raw (str): The stripped line read from the file.
        label (str): Human-readable name used in error messages
        ('entry' / 'exit').

    Returns:
        tuple[int, int]: A (row, col) integer tuple.

    Raises:
        ValueError: If the line cannot be parsed as two integers.
    """
    cleaned = raw.strip().lstrip("(").rstrip(")")
    parts = cleaned.split(",")
    if len(parts) != 2:
        raise ValueError(
            f"Invalid {label} coordinate '{raw}': expected two integers "
            "in '(row, col)' or 'row,col' format."
        )
    try:
        return int(parts[1].strip()), int(parts[0].strip())
    except ValueError:
        raise ValueError(
            f"Invalid {label} coordinate '{raw}':"
            "both values must be integers."
        )


def _validate_grid(grid: list[str], filename: str) -> None:
    """Ensures every row is non-empty, same length, and contains
    only hex digits.

    Args:
        grid (list[str]): List of row strings extracted from the file.
        filename (str): Source filename, used in error messages.

    Raises:
        ValueError: If the grid is empty, has inconsistent row widths,
            or contains characters outside the hex alphabet.
    """
    if not grid:
        raise ValueError(f"'{filename}' contains no grid data.")

    expected_width = len(grid[0])
    for row_idx, row in enumerate(grid):
        if len(row) != expected_width:
            raise ValueError(
                f"Row {row_idx} has width {len(row)}, "
                f"expected {expected_width} (from row 0)."
            )
        invalid = set(row) - _VALID_HEX_CHARS
        if invalid:
            raise ValueError(
                f"Row {row_idx} contains non-hex characters: {invalid!r}."
            )


def _validate_path(path_str: str) -> None:
    """Ensures the path string contains only the letters N, E, S, W.

    Args:
        path_str (str): The path string read from the file.

    Raises:
        ValueError: If the string contains any character outside {N, E, S, W}.
    """
    invalid = set(path_str) - _VALID_PATH_CHARS
    if invalid:
        raise ValueError(
            f"Path string contains invalid characters: {invalid!r}. "
            "Only N, E, S, W are allowed."
        )


def parse_exported_file(
    filename: str,
) -> tuple[list[str], tuple[int, int], tuple[int, int], str]:
    """Parses a maze output file and returns its four structural elements.

    The expected file format is:
        <hex grid, one row per line>
        <blank line>
        <entry coordinates: row,col>
        <exit coordinates: row,col>
        <path string using N/E/S/W characters>

    Args:
        filename (str): Path to the maze output file to parse.

    Returns:
        tuple[list[str], tuple[int, int], tuple[int, int], str]:
        A tuple containing:
            - grid (list[str]): One hex-encoded string per row.
            - entry (tuple[int, int]): (row, col) of entry cell.
            - exit_coord (tuple[int, int]): (row, col) of exit cell.
            - path_str (str): Shortest path string (N/E/S/W).

    Raises:
        FileNotFoundError: If filename does not exist.
        ValueError: If the file is malformed or fails validation.
    """
    try:
        with open(filename, "r") as f:
            lines = [line.rstrip("\n") for line in f]
    except FileNotFoundError:
        raise FileNotFoundError(f"Maze file not found: '{filename}'.")

    # --- Section 1: grid rows (everything before the first blank line) -------
    grid: list[str] = []
    idx = 0
    while idx < len(lines) and lines[idx].strip() != "":
        grid.append(lines[idx].strip())
        idx += 1

    _validate_grid(grid, filename)

    # --- Skip the mandatory blank separator ----------------------------------
    idx += 1

    # --- Section 2: entry coordinates ----------------------------------------
    if idx >= len(lines):
        raise ValueError(f"'{filename}' is missing the entry coordinate line.")
    entry = _parse_coord(lines[idx].strip(), "entry")
    idx += 1

    # --- Section 3: exit coordinates -----------------------------------------
    if idx >= len(lines):
        raise ValueError(f"'{filename}' is missing the exit coordinate line.")
    exit_coord = _parse_coord(lines[idx].strip(), "exit")
    idx += 1

    # --- Section 4: solution path --------------------------------------------
    if idx >= len(lines):
        raise ValueError(f"'{filename}' is missing the path string line.")
    path_str = lines[idx].strip()
    _validate_path(path_str)

    return grid, entry, exit_coord, path_str


def compute_logo_cells(width: int, height: int) -> list[tuple[int, int]]:
    """Calculates the (row, col) cells occupied by the centered AreaLogo.

    Args:
        width (int): Total width of the maze grid.
        height (int): Total height of the maze grid.

    Returns:
        list[tuple[int, int]]: List of (row, col) cell coordinates occupied
        by the logo pattern, or an empty list if dimensions are too small.
    """
    logo = AreaLogo()
    pattern = logo.pattern
    logo_h = logo.dimension.height
    logo_w = logo.dimension.width

    fits = width >= logo_w + 2 and height >= logo_h + 2
    if not fits:
        return []

    offset_col = int(width / 2) - int(logo_w / 2)
    offset_row = int(height / 2) - int(logo_h / 2)

    cells: list[tuple[int, int]] = []
    for y in range(logo_h):
        for x in range(logo_w):
            if pattern[y][x]:
                cells.append((offset_row + y, offset_col + x))
    return cells
