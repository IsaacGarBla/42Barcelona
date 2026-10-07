#!/usr/bin/env python3

from typing import Any


def destroy_environment(param: dict[str, Any]) -> int:
    """Safely shuts down the graphics window and exits the operational loop.

    Args:
        param: Dictionary containing the MLX context with keys:
            - mlx_instance: The MLX object managing the window.
            - mlx_ptr: The pointer to the active MLX window instance.

    Returns:
        Always returns 0 to signal successful termination.
    """
    try:
        m: Any = param["mlx_instance"]
        mlx_ptr: Any = param["mlx_ptr"]
        m.mlx_loop_exit(mlx_ptr)
    except (KeyboardInterrupt, Exception):
        pass
    return 0
