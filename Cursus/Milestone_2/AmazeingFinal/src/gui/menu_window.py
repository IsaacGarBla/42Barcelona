#!/usr/bin/env python3
"""Module for rendering and managing the main menu window using MiniLibX."""

from typing import Any
from .handle_menu_keyboard import handle_menu_keys
from .close_window import destroy_environment
from .config import MENU_HEIGHT, MENU_WIDTH
from .config import KEY_ESC_LINUX, WINDOW_CLOSE_EVENT
from .config import (
    COLOR_RED, COLOR_WHITE,
    COLOR_BRIGHT_RED,
    COLOR_TITLE_MAIN, COLOR_TITLE_SUB
)


def render_menu(param: dict[str, Any]) -> int:
    """Renders the main menu user interface elements to the MiniLibX window.

    Args:
        param (dict[str, Any]): Shared context dictionary containing MLX
            handles, user menu selections, and frame counters.

    Returns:
        int: Always returns 0 as required by MiniLibX hook callback
        definitions.
    """
    m = param["mlx_instance"]
    mlx_ptr = param["mlx_ptr"]
    win_ptr = param["win_ptr"]

    m.mlx_clear_window(mlx_ptr, win_ptr)

    m.mlx_string_put(mlx_ptr, win_ptr, 280, 100, COLOR_TITLE_MAIN,
                     " A-MAZE-ING ")
    m.mlx_string_put(mlx_ptr, win_ptr, 310, 130, COLOR_TITLE_SUB,
                     " V I S U A L I Z E R ")
    m.mlx_string_put(mlx_ptr, win_ptr, 100, 160, COLOR_TITLE_MAIN,
                     " ___________________________________________"
                     "______________ ")
    m.mlx_string_put(mlx_ptr, win_ptr, 80, 220, COLOR_RED,
                     " CHOOSE RENDERING MODE: ")
    m.mlx_string_put(mlx_ptr, win_ptr, 110, 260, COLOR_WHITE,
                     " [1] Terminal ASCII Rendering ")
    m.mlx_string_put(mlx_ptr, win_ptr, 110, 290, COLOR_WHITE,
                     " [2] Graphical Window Rendering ")
    m.mlx_string_put(mlx_ptr, win_ptr, 80, 350, COLOR_BRIGHT_RED,
                     " Press ESC to Quit ")

    param["frame_count"] += 1
    return 0


def show_menu_window(m: Any, mlx_ptr: Any) -> str:
    """Displays the interactive main menu window and captures the
    user's selection.

    Args:
        m (Any): MiniLibX instance module wrapper.
        mlx_ptr (Any): Active MiniLibX context pointer.

    Returns:
        str: A string representing the chosen rendering mode
        ("1", "2", or "none").
    """
    win_ptr = m.mlx_new_window(mlx_ptr, MENU_WIDTH, MENU_HEIGHT,
                               "A-Maze-ing - Menu")

    context: dict[str, Any] = {
        "mlx_instance": m,
        "mlx_ptr": mlx_ptr,
        "win_ptr": win_ptr,
        "choice": "none",
        "frame_count": 0
    }

    m.mlx_expose_hook(win_ptr, render_menu, context)
    m.mlx_key_hook(win_ptr, handle_menu_keys, context)
    m.mlx_hook(win_ptr, WINDOW_CLOSE_EVENT, KEY_ESC_LINUX,
               destroy_environment, context)
    m.mlx_loop(mlx_ptr)
    m.mlx_destroy_window(mlx_ptr, win_ptr)
    choice = context["choice"]
    if isinstance(choice, str):
        return choice
    return "none"
