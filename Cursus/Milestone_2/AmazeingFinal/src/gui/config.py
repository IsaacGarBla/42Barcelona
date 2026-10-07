# Window Event Codes
WINDOW_CLOSE_EVENT: int = 33
DEFAULT_MASK: int = 0
RESIZE_EVENT: int = 22

# System Keycodes (Mac / Linux fallback equivalents)
KEY_ESC_MAC: int = 53
KEY_ESC_LINUX: int = 65307
KEY_1: int = 49       # Standard '1' Key to enter the maze
KEY_2: int = 50       # Standard '2' Key to enter the maze
KEY_R: int = 114       # 'R' key to regenerate maze profile
KEY_H: int = 104        # 'H' key to toggle path visibility
KEY_C: int = 99        # 'C' key to change wall colors
KEY_M: int = 109   # 'M' key to randomize marker colors
KEY_P: int = 112   # 'P' key to cycle path color
KEY_L: int = 108   # 'L' key to cycle logo color
KEY_T: int = 116   # 'T' key to print terminal

# Layout Scale & Spacing Configuration
CELL_SIZE: int = 30
OFFSET_X: int = 40   # Grid spacing margin left
OFFSET_Y: int = 40   # Grid spacing margin top

# Shared UI Component Layout Dimensions
MENU_WIDTH: int = 800
MENU_HEIGHT: int = 500

ERROR_WINDOW_WIDTH: int = 650
ERROR_WINDOW_HEIGHT: int = 180

# Color Theme Array Palette (Standard 24-bit RGB hex tokens: 0xRRGGBB)
WALL_COLORS: list[int] = [
    0xFFFFFFFF,  # White  (AA=FF, fully opaque)
    0xFF00FF00,  # Green
    0xFF0000FF,  # Blue
    0xFFFFFF00,  # Yellow
]
# Terminal UI Utility Colors in ASCII

TERM_BG_BLACK = "\033[40m"
TERM_BG_RED = "\033[41m"
TERM_BG_GREEN = "\033[42m"
TERM_BG_YELLOW = "\033[43m"
TERM_BG_BLUE = "\033[44m"
TERM_BG_MAGENTA = "\033[45m"
TERM_BG_CYAN = "\033[46m"
TERM_BG_WHITE = "\033[47m"

TERM_BG_BRIGHT_BLACK = "\033[100m"
TERM_BG_BRIGHT_RED = "\033[101m"
TERM_BG_BRIGHT_GREEN = "\033[102m"
TERM_BG_BRIGHT_YELLOW = "\033[103m"
TERM_BG_BRIGHT_BLUE = "\033[104m"
TERM_BG_BRIGHT_MAGENTA = "\033[105m"
TERM_BG_BRIGHT_CYAN = "\033[106m"
TERM_BG_BRIGHT_WHITE = "\033[107m"

TERM_RESET = "\033[0m"

# Graphical UI Utility Colors en BGR
COLOR_BLACK = 0x121212
COLOR_RED = 0x0000FF  # El FF pasa al final (canal Azul en BGR es Rojo)
COLOR_GREEN = 0x33FF33  # El verde se queda igual al estar en el centro
COLOR_YELLOW = 0x00CCFF  # Invertido
COLOR_BLUE = 0xFF6633  # Invertido
COLOR_CYAN = 0xFFFF33  # Invertido
COLOR_WHITE = 0xFFFFFF
COLOR_BRIGHT_BLACK = 0x3A3A3A
COLOR_BRIGHT_RED = 0x6666FF  # Corregido a BGR
COLOR_BRIGHT_GREEN = 0x66FF66  # El verde se mantiene en el centro
COLOR_BRIGHT_YELLOW = 0x66FFFF  # Corregido a BGR
COLOR_BRIGHT_BLUE = 0xFF9966  # Corregido a BGR
COLOR_BRIGHT_MAGENTA = 0xFF66FF  # Al ser simétrico (FF y FF) se queda igual
COLOR_BRIGHT_CYAN = 0xFFFF66  # Corregido a BGR
COLOR_BRIGHT_WHITE = 0xF0F0F0

COLOR_TITLE_MAIN = 0x00FFCC  # Cyan neón
COLOR_TITLE_SUB = 0xFFFF00  # Amarillo neón
COLOR_SHADOW = 0x1A1A1A  # Gris oscuro/Sombra
COLOR_TEXT = 0xFFFFFF  # Blanco para las opciones
COLOR_ALERT = 0xFF00FF  # Magenta para el botón de salir


# Visualizer UI Colors (0xAABBGGRR)
COLOR_UI:    int = 0xFF00FF00   # green
COLOR_INFO:  int = 0xFFFFFFFF   # white
COLOR_PATH:  int = 0xFF00FFFF   # cyan  ← color inicial del path

COLOR_ENTRY: int = 0xFF00FF00   # green  ← alpha primero
COLOR_EXIT:  int = 0xFF0000FF   # red    ← alpha primero

MARKER_COLORS: tuple[int, int] = (COLOR_ENTRY, COLOR_EXIT)

PATH_COLORS: list[int] = [
    0xFF00FFFF,   # cyan
    0xFFFF00FF,   # magenta
    0xFFFFFF00,   # yellow
    0xFF00FF88,   # mint
    0xFF0088FF,   # orange
]

LOGO_COLORS = [
    0xFF00FFFF,   # cyan
    0xFFFF00FF,   # magenta
    0xFFFFFF00,   # yellow
    0xFF00FF88,   # mint
    0xFF0088FF,   # orange
]

# Max MAZE size to fit window or terminal
MAX_WIDTH_WINDOW = 126
MAX_HEIGHT_WINDOW = 51
MAX_WIDTH_TERMINAL = 105
MAX_HEIGHT_TERMINAL = 24
