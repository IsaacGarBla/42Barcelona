from .colors import ThemeColor
from mazegen.maze import Maze
from mazegen.direction import (Direction, Offset)
from mazegen.coordinate import Coordinate
from .exceptions import PrintTerminalError
from .config import (MAX_HEIGHT_TERMINAL, MAX_WIDTH_TERMINAL)
import time
import sys
import os
import shutil
import signal
from types import FrameType


class Printer:
    """
    Class responsible for printing the maze to the terminal.
    """

    _maze: Maze

    def __init__(self, m: Maze) -> None:
        """
        Initialize the Printer with a Maze instance.

        Args:
                m: The Maze instance to print.
        """

        self._maze = m

    def to_terminal(self, theme: ThemeColor,
                    delay: float = 0.05) -> None:
        """
        Print the maze to the terminal with the specified theme and delay.

        Args:
            theme: The ThemeColor instance to use for coloring the maze.
            delay: The delay in seconds between printing each step of the maze.

        If the Maze doesn't fit in the terminal,
        it raises a PrintTerminalError.
        """

        screen: list[list[tuple[str, str]]] = []
        redim: bool = False
        screen_dim: os.terminal_size

        def clear_screen() -> None:
            """
            Clear the terminal screen using ANSI escape codes.
            """

            # 1. \033[H  -> Mueve el cursor al origen
            # (esquina superior izquierda)
            # 2. \033[2J -> Limpia toda la pantalla visible actual
            # 3. \033[3J -> Limpia el buffer de scrollback completo
            print("\033[H\033[2J\033[3J", end="", flush=True)

        def print_screen() -> None:
            """
            Print the current screen representation of
            the maze to the terminal.
            """

            buffer: str
            nonlocal redim
            up_margin: int
            left_margin: int

            if redim:
                clear_screen()
                redim = False
                # screen_dim = shutil.get_terminal_size()

            up_margin = (screen_dim.lines -
                         (self._maze.dimension.height * 2 + 1)) // 2
            left_margin = (screen_dim.columns -
                           (self._maze.dimension.width * 2 + 1)) // 2
            # [H Moves cursor at the beginning.
            buffer = "\033[H" + ("\n" * up_margin)
            for row in range(self._maze.dimension.height * 2 + 1):
                buffer += (" " * left_margin)
                for col in range(self._maze.dimension.width * 2 + 1):
                    buffer += f"{screen[row][col][0]}{screen[row][col][1]}"
                buffer += "\033[0m\n"
            print(buffer, end="", flush=True)

        def hide_cursor() -> None:
            """Hide the cursor in the terminal."""

            sys.stdout.write("\033[?25l")
            sys.stdout.flush()

        def show_cursor() -> None:
            """Show the cursor in the terminal."""
            sys.stdout.write("\033[?25h")
            sys.stdout.flush()

        def print_path() -> None:
            """Print the shortest path from entry to exit in the maze."""
            current: Coordinate
            nonlocal redim

            current = self._maze.entry
            screen[current.y * 2 + 1][current.x * 2 + 1] = (theme.entry_color,
                                                            " ")
            screen[self._maze.exit.y * 2 + 1][self._maze.exit.x * 2 + 1] = \
                (theme.exit_color, " ")
            for mov in self._maze.shortest_sol:
                match mov:
                    case Direction.NORTH:
                        screen[current.y * 2 + 1 - 1][current.x * 2 + 1] = \
                            (theme.path_color, " ")
                        screen[current.y * 2 + 1 - 2][current.x * 2 + 1] = \
                            (theme.path_color, " ")
                    case Direction.EAST:
                        screen[current.y * 2 + 1][current.x * 2 + 1 + 1] = \
                            (theme.path_color, " ")
                        screen[current.y * 2 + 1][current.x * 2 + 1 + 2] = \
                            (theme.path_color, " ")
                    case Direction.SOUTH:
                        screen[current.y * 2 + 1 + 1][current.x * 2 + 1] = \
                            (theme.path_color, " ")
                        screen[current.y * 2 + 1 + 2][current.x * 2 + 1] = \
                            (theme.path_color, " ")
                    case Direction.WEST:
                        screen[current.y * 2 + 1][current.x * 2 + 1 - 1] = \
                            (theme.path_color, " ")
                        screen[current.y * 2 + 1][current.x * 2 + 1 - 2] = \
                            (theme.path_color, " ")
                    case _:
                        pass
                screen[self._maze.exit.y * 2 + 1][self._maze.exit.x * 2 + 1] =\
                    (theme.exit_color, " ")
                current = current.add_offset(Offset.offsets[mov])
                if redim:
                    adjust_screen_size()
                    redim = False
                print_screen()
                time.sleep(delay * 2)

        def create_screen_maze_empty() -> None:
            """
            Create an empty screen representation of
            the maze
            """
            nonlocal screen

            screen = [[(theme.border_color, " ")] *
                      (self._maze.dimension.width * 2 + 1)
                      for _ in range(self._maze.dimension.height * 2 + 1)]
            # Crear matriz vacía.
            for col in range(0, self._maze.dimension.width * 2 + 1):
                screen[0][col] = (theme.border_color, " ")
                screen[self._maze.dimension.height * 2][col] = \
                    (theme.border_color, " ")
            for row in range(1, self._maze.dimension.height * 2):
                for col in range(self._maze.dimension.width * 2 + 1):
                    if col % 2 == 0:
                        screen[row][col] = (theme.border_color, " ")
                    elif row % 2 == 0:
                        screen[row][col] = (theme.border_color, " ")
                    else:
                        screen[row][col] = (theme.back_color, " ")

        def print_maze_in_order_creation() -> None:
            """
            Print the maze in the order it was created,
            showing the creation path.
            """

            nonlocal redim

            for coor in self._maze.board.blocked_boxes:
                screen[coor.y * 2 + 1][coor.x * 2 + 1] = (theme.logo_color,
                                                          " ")
                time.sleep(delay)
                if redim:
                    adjust_screen_size()
                    redim = False
                print_screen()
            for coor, dir in self._maze.creation_path:
                screen[coor.y * 2 + 1][coor.x * 2 + 1] = (theme.pen_color, " ")
                if redim:
                    adjust_screen_size()
                    redim = False
                print_screen()
                match dir:
                    case Direction.EAST:
                        # Tirar lado EAST
                        screen[coor.y * 2 + 1][(coor.x + 1) * 2] =\
                            (theme.back_color, " ")
                    case Direction.SOUTH:
                        screen[(coor.y + 1) * 2][coor.x * 2 + 1] =\
                            (theme.back_color, " ")
                    case Direction.WEST:
                        screen[coor.y * 2 + 1][coor.x * 2] =\
                            (theme.back_color, " ")
                    case Direction.NORTH:
                        screen[coor.y * 2][coor.x * 2 + 1] =\
                            (theme.back_color, " ")
                    case _:
                        pass
                screen[coor.y * 2 + 1][coor.x * 2 + 1] = (theme.back_color,
                                                          " ")
                time.sleep(delay)
                if redim:
                    adjust_screen_size()
                    redim = False
                print_screen()

        def adjust_screen_size() -> None:
            """
            Adjust the terminal size to fit the maze if necessary.
            """
            nonlocal screen_dim
            min_width: int
            min_height: int

            clear_screen()
            min_width = (self._maze.dimension.width * 2 + 1) + 1
            min_height = (self._maze.dimension.height * 2 + 1) + 1
            # Asegurar que la pantalla se redimensiona correctamente
            screen_dim = shutil.get_terminal_size()
            if screen_dim.lines < min_height or \
               screen_dim.columns < min_width:
                # Si es más pequeña de lo permitido, forzar el tamaño mínimo
                # Secuencia ANSI para redimensionar
                # terminal: \x1b[8;FILAS;COLUMNASt
                print(f"\x1b[8;{min_height};{min_width}t", end="", flush=True)

        def notificar_redimension(signum: int, frame: FrameType | None
                                  ) -> None:
            """
            Signal handler for terminal resize events (SIGWINCH).
            Sets the redim flag to True to indicate that the terminal
            has been resized.
            """

            nonlocal redim
            redim = True

        if not (self._maze.dimension.width <= MAX_WIDTH_TERMINAL and
                self._maze.dimension.height <= MAX_HEIGHT_TERMINAL):
            raise PrintTerminalError("Dimensions are too large for"
                                     " the terminal")
        adjust_screen_size()
        hide_cursor()
        create_screen_maze_empty()
        clear_screen()
        signal.signal(signal.SIGWINCH, notificar_redimension)
        print_maze_in_order_creation()
        print_path()
        show_cursor()
        signal.signal(signal.SIGWINCH, signal.SIG_IGN)
