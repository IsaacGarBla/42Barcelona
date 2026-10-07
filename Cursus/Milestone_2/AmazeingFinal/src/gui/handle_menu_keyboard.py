from typing import Any
from .close_window import destroy_environment
from .config import KEY_ESC_LINUX, KEY_1, KEY_2


def handle_menu_keys(key: int, param: dict[str, Any]) -> None:
    """Handles keyboard input on the menu window.

    Maps key presses to user choices and shuts down the menu loop.
    Pressing ESC exits without a choice, KEY_1 selects terminal mode,
    and KEY_2 selects window mode.

    Args:
        key: The key code of the pressed key.
        param: Dictionary containing the MLX context and shared state
        with keys:
            - mlx_instance: The MLX object managing the window.
            - mlx_ptr: The pointer to the active MLX window instance.
            - choice: Updated in-place with "terminal" or "window".
    """
    try:
        if key == KEY_ESC_LINUX:
            destroy_environment(param)
        elif key == KEY_1:
            param["choice"] = "terminal"
            destroy_environment(param)
        elif key == KEY_2:
            param["choice"] = "window"
            destroy_environment(param)
    except KeyboardInterrupt:
        destroy_environment(param)
