#!/usr/bin/env python3

from typing import Any, cast
from .config import PATH_COLORS
from .close_window import destroy_environment
from .handle_window_keyboard import handle_visualizer_keys
from .config import MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW
from .exceptions import PrintScreenError
from mazegen import Maze
from .config import (
    KEY_ESC_LINUX,
    WINDOW_CLOSE_EVENT,
    WALL_COLORS,
    OFFSET_X,
    OFFSET_Y,
    CELL_SIZE,
    COLOR_UI,
    COLOR_INFO,
    MARKER_COLORS,
    LOGO_COLORS
)
from .window_utils import (
    draw_square,
    draw_maze_walls,
    draw_solution_path,
    parse_exported_file,
    compute_logo_cells,
)


def _compute_window_size(
    num_rows: int, num_cols: int,
) -> tuple[int, int, int]:
    """Calculates window dimensions and the HUD panel Y-offset.

    Args:
        num_rows (int): Number of rows in the maze grid.
        num_cols (int): Number of columns in the maze grid.

    Returns:
        tuple[int, int, int]: A tuple containing
        (window_width, window_height, menu_y_start).
    """
    maze_w = num_cols * CELL_SIZE
    maze_h = num_rows * CELL_SIZE
    menu_h = 300
    menu_w = 300

    window_width = max(maze_w, menu_w) + OFFSET_X * 2
    window_height = maze_h + menu_h + OFFSET_Y * 3
    menu_y_start = OFFSET_Y + maze_h + OFFSET_Y

    return window_width, window_height, menu_y_start


def _render_hud(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    menu_y_start: int,
    show_path: bool,
    seed: int,
) -> None:
    """Renders the live controls and status HUD below the maze grid.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        menu_y_start (int): Y-coordinate offset to start drawing the HUD.
        show_path (bool): Indicates whether the solution path is visible.
        seed (int): The seed value used to generate the current maze.
    """
    y = menu_y_start
    path_status = "SHOWN" if show_path else "HIDDEN"
    m.mlx_clear_window(mlx_ptr, win_ptr)
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y,       COLOR_UI,
                     f"Seed: {seed}")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 30,  COLOR_UI,
                     "=== LIVE CONTROLS ===")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 60,  COLOR_INFO,
                     "[R] - Regenerate Maze")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 90,  COLOR_INFO,
                     f"[H] - Hide/Show Path ({path_status})")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 120, COLOR_INFO,
                     "[C] - Cycle Wall Color")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 150, COLOR_INFO,
                     "[M] - Randomize Marker Colors")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 180, COLOR_INFO,
                     "[L] - Cycle Logo Color")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 210, COLOR_INFO,
                     "[T] - Print Terminal")
    m.mlx_string_put(mlx_ptr, win_ptr, OFFSET_X, y + 240, COLOR_INFO,
                     "[ESC] - Exit Visualizer")


def _render_markers(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    entry: tuple[int, int],
    exit_coord: tuple[int, int],
    marker_colors: tuple[int, int],
) -> None:
    """Draws the entry and exit markers on the maze grid.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        entry (tuple[int, int]): Entry cell coordinates (col, row).
        exit_coord (tuple[int, int]): Exit cell coordinates (col, row).
        marker_colors (tuple[int, int]): Entry and exit BGR color values.
    """
    margin = 5
    size = CELL_SIZE - margin * 2

    draw_square(m, mlx_ptr, win_ptr,
                OFFSET_Y + entry[1] * CELL_SIZE + margin,
                OFFSET_X + entry[0] * CELL_SIZE + margin,
                size, marker_colors[0])
    draw_square(m, mlx_ptr, win_ptr,
                OFFSET_Y + exit_coord[1] * CELL_SIZE + margin,
                OFFSET_X + exit_coord[0] * CELL_SIZE + margin,
                size, marker_colors[1])


def _render_logo(
    m: Any, mlx_ptr: Any, win_ptr: Any,
    logo_cells: list[tuple[int, int]],
    color: int,
) -> None:
    """Draws the embedded logo cells on the grid.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        logo_cells (list[tuple[int, int]]): Grid cells belonging
        to the logo pattern.
        color (int): BGR color integer for the logo cells.
    """
    margin = 5
    size = CELL_SIZE - margin * 2
    for row, col in logo_cells:
        draw_square(m, mlx_ptr, win_ptr,
                    OFFSET_Y + col * CELL_SIZE + margin,
                    OFFSET_X + row * CELL_SIZE + margin,
                    size, color)


def render_scene(param: dict[str, Any]) -> int:
    """Expose-hook callback that repaints the complete visualizer frame.

    Args:
        param (dict[str, Any]): Shared state dictionary with MLX
        handles and maze state.

    Returns:
        int: Always returns 0 as required by MLX hook callbacks.
    """
    try:
        if param.get("state") != "VISUALIZER":
            return 0

        m = param["mlx_instance"]
        mlx_ptr = param["mlx_ptr"]
        win_ptr = param["win_ptr"]
        img_ptr = param["img_ptr"]

        wall_color = WALL_COLORS[cast(int, param["color_idx"])]
        logo_color = LOGO_COLORS[cast(int, param["logo_color_idx"])]
        m.mlx_sync(mlx_ptr, m.SYNC_IMAGE_WRITABLE, img_ptr)
        m.mlx_clear_window(mlx_ptr, win_ptr)
        _render_hud(m, mlx_ptr, win_ptr, param["menu_y_start"],
                    param["show_path"], param["valid_dict"]["SEED"])
        _render_markers(m, mlx_ptr, win_ptr, param["entry"],
                        param["exit_coord"], param["marker_colors"])
        _render_logo(m, mlx_ptr, win_ptr, param["logo_cells"], logo_color)
        m.mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0)
        m.mlx_sync(mlx_ptr, m.SYNC_WIN_FLUSH, win_ptr)
        if param["show_path"]:
            draw_solution_path(
                m, mlx_ptr, win_ptr,
                param["path_str"],
                param["entry"],
                param["exit_coord"],
                OFFSET_X, OFFSET_Y, CELL_SIZE,
                PATH_COLORS[param["path_color_idx"]],
            )

        draw_maze_walls(
            m, mlx_ptr, win_ptr,
            param["grid"],
            wall_color,
            OFFSET_X, OFFSET_Y, CELL_SIZE,
        )
    except KeyboardInterrupt:
        destroy_environment(param)
    return 0


def _build_shared_data(
    m: Any, mlx_ptr: Any, win_ptr: Any, img_ptr: Any,
    filename: str,
    valid_dict: dict[str, Any],
    grid: list[str],
    entry: tuple[int, int],
    exit_coord: tuple[int, int],
    path_str: str,
    menu_y_start: int,
    logo_cells: list[tuple[int, int]],
    maze: Maze
) -> dict[str, Any]:
    """Constructs the shared-state dictionary passed across MLX callbacks.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): MLX context pointer.
        win_ptr (Any): Active window pointer.
        img_ptr (Any): MLX image buffer pointer.
        filename (str): Path to the maze file.
        valid_dict (dict[str, Any]): Validated configuration dictionary.
        grid (list[str]): Encoded maze grid strings.
        entry (tuple[int, int]): Entry cell coordinates.
        exit_coord (tuple[int, int]): Exit cell coordinates.
        path_str (str): Solution path direction string.
        menu_y_start (int): Y offset for the HUD panel.
        logo_cells (list[tuple[int, int]]): Coordinates for logo cells.
        maze (Maze): Maze instance.

    Returns:
        dict[str, Any]: Shared state dictionary containing window
        references and settings.
    """
    return {
        "state":         "VISUALIZER",
        "mlx_instance":  m,
        "mlx_ptr":       mlx_ptr,
        "win_ptr":       win_ptr,
        "img_ptr":       img_ptr,
        "map_filename":  filename,
        "valid_dict":    valid_dict,
        "grid":          grid,
        "entry":         entry,
        "exit_coord":    exit_coord,
        "path_str":      path_str,
        "show_path":     True,
        "color_idx":     0,
        "menu_y_start":  menu_y_start,
        "marker_colors": MARKER_COLORS,
        "path_color_idx": 0,
        "logo_cells":    logo_cells,
        "logo_color_idx": 0,
        "maze":           maze
    }


def start_visualizer(m: Any, mlx_ptr: Any, valid_dict: dict[str, Any],
                     filename: str, maze: Maze) -> None:
    """Launches and manages the interactive GUI maze visualizer window.

    Args:
        m (Any): MLX instance module.
        mlx_ptr (Any): Active MLX context pointer.
        valid_dict (dict[str, Any]): Validated maze parameters
        (WIDTH, HEIGHT, SEED, etc.).
        filename (str): Target maze file path to parse.
        maze (Maze): Instantiated maze object.

    Raises:
        PrintScreenError: If requested maze dimensions exceed maximum
        supported window bounds.
    """
    grid, entry, exit_coord, path_str = parse_exported_file(filename)

    if (valid_dict["HEIGHT"] > MAX_HEIGHT_WINDOW) or (
            valid_dict["WIDTH"] > MAX_WIDTH_WINDOW):
        raise PrintScreenError
    num_rows = valid_dict["HEIGHT"]
    num_cols = valid_dict["WIDTH"]

    logo_cells = compute_logo_cells(num_cols, num_rows)
    window_width, window_height, menu_y_start = _compute_window_size(
        num_rows, num_cols)

    win_ptr = m.mlx_new_window(mlx_ptr, window_width, window_height,
                               "A-MAZE-ING VISUALIZER")
    img_ptr = m.mlx_new_image(mlx_ptr, window_width, window_height,)
    shared_data = _build_shared_data(
        m, mlx_ptr, win_ptr, img_ptr,
        filename, valid_dict, grid, entry, exit_coord, path_str,
        menu_y_start, logo_cells, maze
    )

    m.mlx_key_hook(win_ptr, handle_visualizer_keys, shared_data)
    m.mlx_hook(win_ptr, WINDOW_CLOSE_EVENT, KEY_ESC_LINUX,
               destroy_environment, shared_data)
    m.mlx_expose_hook(win_ptr, render_scene, shared_data)

    m.mlx_loop(mlx_ptr)
    m.mlx_destroy_window(mlx_ptr, win_ptr)

    m.mlx_release(mlx_ptr)
