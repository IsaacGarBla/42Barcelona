#!/usr/bin/env python3

import random
from typing import Any
from .close_window import destroy_environment
from .config import (KEY_ESC_LINUX, KEY_R, KEY_H, KEY_C, KEY_M, KEY_P,
                     KEY_L, KEY_T, WALL_COLORS, PATH_COLORS, LOGO_COLORS)
from .window_utils import parse_exported_file
from mazegen import Maze, Coordinate, Dimension, AreaLogo
from src.gui import Printer, ThemeColor
from src.gui.exceptions import PrintTerminalError
import sys

_seed_rng = random.Random()


def _random_bgr() -> int:
    """Returns a random opaque color in 0xAABBGGRR format."""
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    return (0xFF << 24) | (b << 16) | (g << 8) | r


def _action_exit(param: dict[str, Any]) -> None:
    """Closes the visualizer window and releases the MLX context."""
    destroy_environment(param)


def _action_toggle_path(param: dict[str, Any]) -> None:
    """Flips the show_path flag and triggers a redraw."""
    param["show_path"] = not param["show_path"]
    _redraw(param)


def _action_cycle_color(param: dict[str, Any]) -> None:
    """Advances to the next wall color in the palette and triggers a redraw."""
    param["color_idx"] = (param["color_idx"] + 1) % len(WALL_COLORS)
    _redraw(param)


def _action_randomize_markers(param: dict[str, Any]) -> None:
    """Assigns two distinct random BGR colors to the entry and exit markers."""
    entry_color = _random_bgr()
    exit_color = _random_bgr()
    while exit_color == entry_color:
        exit_color = _random_bgr()
    param["marker_colors"] = (entry_color, exit_color)
    _redraw(param)


def _action_regenerate(param: dict[str, Any]) -> None:
    """Reloads the maze file from disk and triggers a redraw."""
    try:
        vd = param["valid_dict"]
        vd["SEED"] = _seed_rng.randint(1, 1000)
        new_maze = Maze(
            Dimension(vd["HEIGHT"], vd["WIDTH"]),
            Coordinate(*vd["ENTRY"]),
            Coordinate(*vd["EXIT"]),
            vd["SEED"],
            vd["PERFECT"],
            logo=AreaLogo())
        new_maze.export(param["map_filename"])
        grid, entry, exit_coord, path_str = \
            parse_exported_file(param["map_filename"])
        param["grid"] = grid
        param["entry"] = entry
        param["exit_coord"] = exit_coord
        param["path_str"] = path_str
        param["SEED"] = vd["SEED"]
        param["maze"] = new_maze
    except (FileNotFoundError, ValueError) as e:
        print(f"[WARN] Could not reload maze file: {e}")
    _redraw(param)


def _action_cycle_path_color(param: dict[str, Any]) -> None:
    """Advances to the next path color in the palette."""
    param["path_color_idx"] = (param.get(
        "path_color_idx", 0) + 1) % len(PATH_COLORS)
    _redraw(param)


def _redraw(param: dict[str, Any]) -> None:
    """Forces a window repaint by calling the expose hook manually."""
    from .maze_window import render_scene
    render_scene(param)


def _action_cycle_color_logo(param: dict[str, Any]) -> None:
    """Advances to the next logo color in the palette and triggers a redraw."""
    param["logo_color_idx"] = (param.get(
        "logo_color_idx", 0) + 1) % len(LOGO_COLORS)
    _redraw(param)


def _action_print_terminal(param: dict[str, Any]) -> None:
    """Prints the current maze to the terminal using the default theme.

    Prints a warning message to stderr if a PrintTerminalError occurs.
    """
    try:
        Printer(param["maze"]).to_terminal(theme=ThemeColor())
    except PrintTerminalError as e:
        sys.stderr.write(f"[STDERR] WARNING: {e}\n")


# ---------------------------------------------------------------------------
# Dispatch table
# ---------------------------------------------------------------------------


_KEY_ACTIONS: dict[int, Any] = {
    KEY_ESC_LINUX: _action_exit,
    KEY_H:         _action_toggle_path,
    KEY_C:         _action_cycle_color,
    KEY_M:         _action_randomize_markers,
    KEY_R:         _action_regenerate,
    KEY_L:         _action_cycle_color_logo,
    KEY_T:         _action_print_terminal,
    KEY_P:         _action_cycle_path_color,
}


def handle_visualizer_keys(key: int, param: dict[str, Any]) -> None:
    """Handles keyboard input on the maze visualizer window.

    Dispatches each key press to its corresponding action via a
    lookup table. Unknown keys are silently ignored.

    Args:
        key:   The key code of the pressed key.
        param: Shared state dictionary containing the MLX context
               and maze data, with at least the following keys:

               - mlx_instance  (Any):        The MLX object.
               - mlx_ptr       (Any):        Pointer to the MLX instance.
               - win_ptr       (Any):        Pointer to the active window.
               - map_filename  (str):        Path to the maze export file.
               - grid          (list[str]):  Hex-encoded maze grid.
               - entry         (tuple):      (row, col) of the entry cell.
               - exit_coord    (tuple):      (row, col) of the exit cell.
               - path_str      (str):        Solution path string (N/E/S/W).
               - show_path     (bool):       Whether the path is visible.
               - color_idx     (int):        Index into WALL_COLORS.
               - marker_colors (tuple):      (entry_color, exit_color) in BGR.
               - menu_y_start  (int):        Y offset for the HUD panel.
    """
    try:
        action = _KEY_ACTIONS.get(key)
        if action is not None:
            action(param)
    except KeyboardInterrupt:
        _action_exit(param)
