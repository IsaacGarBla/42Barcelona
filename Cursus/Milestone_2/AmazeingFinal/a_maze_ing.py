#!/usr/bin/env python3

import sys
from typing import Any
import signal
from src.parser import handle_sigint, parse_maze_config, check_filename
from src.parser import ParserError
from mazegen import ErrorMaze, Maze, Coordinate, Dimension, AreaLogo
from src.gui import show_menu_window, start_visualizer
from src.gui import Printer, ThemeColor, PrintScreenError, PrintTerminalError
import random


def main() -> None:
    """Entry point for the A-Maze-ing visualizer application.

    Parses the configuration file, generates and exports the maze,
    displays the menu, and launches the chosen rendering mode.

    Raises:
        ParserError: If the configuration file is missing or malformed.
        ErrorMaze: If the maze cannot be generated with the given parameters.
        OSError: If the export file cannot be written.
        KeyboardInterrupt: If the user interrupts the program.
        PrintScreenError: If the terminal is too small to render the maze.
    """
    filename: str = ""
    try:
        import mlx
        maze: Maze
        m: Any
        mlx_ptr: Any
        signal.signal(signal.SIGINT, handle_sigint)
        filename = check_filename()
        valid_dict = parse_maze_config()
        if valid_dict.get("SEED") is None:
            valid_dict["SEED"] = random.randint(1, 1000)
        maze = Maze(
            Dimension(valid_dict["HEIGHT"], valid_dict["WIDTH"]),
            Coordinate(*valid_dict["ENTRY"]),
            Coordinate(*valid_dict["EXIT"]),
            valid_dict["SEED"],
            valid_dict["PERFECT"],
            logo=AreaLogo())
        if not maze.fits_logo:
            sys.stderr.write("[STDERR] WARNING: LOGO does not fit in board,"
                             "it is not printed.\n")
        export_file = valid_dict["OUTPUT_FILE"]
        maze.export(export_file)
        m = mlx.Mlx()
        mlx_ptr = m.mlx_init()
        while True:
            user_choice = show_menu_window(m, mlx_ptr)
            if user_choice == "terminal":
                try:
                    Printer(maze).to_terminal(theme=ThemeColor())
                except PrintTerminalError as e:
                    sys.stderr.write(f"[STDERR] WARNING: {e}\n")
            elif user_choice == "window":
                try:
                    start_visualizer(m, mlx_ptr, valid_dict, export_file, maze)
                except PrintTerminalError as e:
                    sys.stderr.write(f"[STDERR] WARNING: {e}\n")
                break
            else:
                print("Menu closed without choice.")
                print("Thank you for using A-maze-ing visualizer!")
                break
    except ParserError as e:
        sys.stderr.write(f"[STDERR] Configuration error: {e}\n")
        sys.exit(1)
    except ErrorMaze as e:
        sys.stderr.write(f"[STDERR] Maze error: {e}\n")
        sys.exit(1)
    except OSError as e:
        sys.stderr.write(f"[STDERR] System error handling '{filename}': {e}\n")
        sys.exit(1)
    except KeyboardInterrupt:
        sys.stderr.write("[STDERR] Program has been interrupted "
                         "by the keyboard.\n")
        sys.exit(1)
    except PrintScreenError as e:
        sys.stderr.write(f"[STDERR] {e}.\n")
        sys.exit(1)
    except ModuleNotFoundError:
        sys.stderr.write(
            "[STDERR] Missing required module 'mlx'. "
            "Please run 'make install' to install all dependencies.\n"
        )
        sys.exit(1)


if __name__ == "__main__":
    main()
