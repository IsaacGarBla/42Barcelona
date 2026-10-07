*This project has been created as part of the 42 curriculum by igarcia- and smilitar.*

# A-Maze-ing

## Description

A-Maze-ing is a maze generator written in Python. Given a configuration file, it generates a random maze — optionally perfect (with a single path between entry and exit) — and writes it to an output file using a hexadecimal wall representation. The maze is also displayed visually using the MinilibX (MLX) graphical library or the terminal, with interactive controls to explore it.

The project also exposes the core maze generation logic as a standalone, reusable Python package (mazegen-*) that can be imported and used independently in other projects.

## Instructions

### Requirements

- Python 3.10 or later
- Linux (the provided MLX library only supports Linux PCs)
- MLX library (provided as `.whl` or source in the project files)

### Installation

For a clean setup, it's recommended to deploy a virtual environment first:

```
python3 -m venv .venv
source .venv/bin/activate
```

Then install all Python dependencies and the MLX graphical library:

```
make install
```

### Run

```
make run
```

Or manually:

```
python3 a_maze_ing.py config.txt
```

A window will appear asking you to select where you want the maze to be generated: on a graphical window or in the terminal.

### Validate the output file

Use this command to create several output files and validate them. DO NOT USE SEED in the config file.

```
make run && make validate
```

### Debug

```
make debug
```

### Lint

To ensure code quality and adherence to style guidelines, you can run the linters using the following commands:

```
make lint
```

OR

```
make lint-strict
```

## Configuration File

The configuration file defines the parameters used to generate the maze — such as its size, entry/exit points, and whether it should be a perfect maze.

The configuration file is a plain text file with one KEY=VALUE pair per line. Lines starting with `#` are treated as comments and ignored.

| Key | Description | Example |
|---|---|---|
| WIDTH | Number of columns (cells) | WIDTH=20 |
| HEIGHT | Number of rows (cells) | HEIGHT=15 |
| ENTRY | Entry cell coordinates (x,y) | ENTRY=0,0 |
| EXIT | Exit cell coordinates (x,y) | EXIT=19,14 |
| OUTPUT_FILE | Name of the output file | OUTPUT_FILE=maze.txt |
| PERFECT | Whether the maze is perfect | PERFECT=True |
| SEED | Optional seed for reproducibility | SEED=42 |

A default `config.txt` is provided at the root of the repository.

## Output File Format

Each cell is encoded as a single hexadecimal digit representing its walls:

| Bit | Direction |
|---|---|
| 0 (LSB) | North |
| 1 | East |
| 2 | South |
| 3 | West |

A wall being closed sets the bit to `1`, open means `0`.

Examples:

- `1111` → closed in all directions → `F` in hexadecimal
- `0000` → open in all directions → `0` in hexadecimal
- `0101` → closed in North and South, open in East and West → `5` in hexadecimal

Cells are written row by row, one row per line. After an empty line, three additional lines are appended:
- Entry coordinates
- Exit coordinates
- Shortest path from entry to exit using `N`, `E`, `S`, `W`

All lines end with a `\n`.

> Cells belonging to the "42" pattern always appear fully closed (`F`) in the output file. 
Their coordinates can also be exported separately via `maze.export_blocked_boxex(filename)`.

## Project Workflow

```
[1] Install Dependencies  ──>  make install
       │
[2] Run Program           ──>  make run / python3 a_maze_ing.py config.txt
       │
[3] Parse & Validate      ──>  Verify KEY=VALUE pairs in configuration file
       │
[4] Parameter Check       ──>  Validate WIDTH, HEIGHT, ENTRY, EXIT, PERFECT, etc.
       │
[5] Execute Algorithm     ──>  Generate the maze structure based on parameters
       │
[6] Export Output         ──>  Encode cells into hexadecimal representation + append path data
       │
[7] UI Selection Prompt   ──>  An MLX prompt asks for your preferred rendering mode
       │
       ├─── [8.1] Terminal ASCII Rendering ──> Displays the maze in the terminal environment
       └─── [8.2] Graphical Window View    ──> Opens an MLX window with walls, entry, exit
```

## Maze Generation Algorithm

### Iterative Depth-First Search (IDFS)

We have implemented the Iterative Depth-First Search (IDFS) algorithm for the maze generation due to its optimal memory efficiency and architectural robustness. Unlike the traditional recursive version, the iterative implementation utilizes an explicit stack in dynamic memory, allowing us to highlight two fundamental advantages:

- **Safety and Scalability**: By managing the stack manually instead of relying on the system's recursive call stack, we completely eliminate the risk of a stack overflow error when generating large-scale mazes.
- **Design Guarantee**: This approach guarantees the creation of a "perfect maze" (a minimum spanning tree), characterized by having no closed loops or isolated islands. This ensures the existence of a single valid path between any two points, delivering a classic visual style with long passages, deep branching, and challenging dead ends.

Choosing Iterative DFS provides us with a highly predictable and secure algorithm that optimizes machine resources while maintaining a complex and smooth gameplay experience.

#### Maze Generation Process Description

The construction follows a structured approach based on the desired layout type:

1. **Generating a Perfect Maze (Single Unique Path)**

   The process always starts by creating a Perfect Maze. Using the IDFS algorithm with a stack to manage backtracking, the generator carves out passages until every cell in the grid has been visited. This guarantees a mathematically perfect maze characterized by two specific traits:
       
   1.1. **No loops**
   
   There are no closed circuits or alternative paths.

   1.2. **A single unique path**
   
   There is exactly one valid route between any two cells in the entire maze.

2. **Generating a Non-Perfect Maze (Braiding / Multi-Path)**

   If the configuration specifies that the maze does not need to be perfect, a braiding or wall-removal step is applied after the initial IDFS generation. The algorithm introduces multiple paths and loops by executing the following actions:

   2.1. **Adding alternative routes**
   
   It removes a controlled percentage of remaining internal walls at random.There is exactly one valid route between any two cells in the entire maze.

   2.2. **Removing dead ends**
   
   It identifies cells that have only one open passage and breaks a random adjacent wall to connect them to another path.

   This intentional breaking of walls _**transforms the structure from a single-path layout into a complex network with multiple alternative routes**_, shortcuts, and loops.


## "42" Pattern

As required by the subject, every generated maze contains a visible "42" pattern drawn using fully closed cells. This is implemented via the `AreaLogo` class, which reserves a fixed set of coordinates (`_blocked_box`) at maze generation time — these cells are excluded from the DFS carving process, guaranteeing they remain fully walled and form the "42" shape when rendered.

If the maze dimensions are too small to fit the pattern, the program prints an error message to the console and generates the maze without the logo, as allowed by the subject.

## Visual Representation

The maze is rendered in a graphical window using the MLX library. The following interactions are available:

- Re-generate a new maze
- Show / Hide the shortest path from entry to exit
- Change wall colours


## Reusable Module: mazegen

This project includes a standalone, production-ready maze generation package called mazegen. It can be built into a `.whl` package, installed via pip, and reused in any other Python project independently from the main application parser or UI.

### 🛠️ Build and Installation

**Step 1: Create the pyproject.toml File**

At the root of your project (`A_maze_ing/`), create a file named `pyproject.toml`. This file tells the Python build tools how to compile your package. 
```toml
[build-system]
requires = ["setuptools>=61.0"]
build-backend = "setuptools.build_meta"

[project]
name = "mazegen"
version = "1.0.0"
description = "Reusable maze generator library"
readme = "README.md"
requires-python = ">=3.10"
classifiers = [
    "Programming Language :: Python :: 3",
]

[tool.setuptools.packages.find]
where = ["."]
include = ["mazegen*"]

[[tool.mypy.overrides]]
module = "mlx.*"
ignore_missing_imports = true
```

**Step 2: Install the Build Tool**

Make sure your virtual environment (`.venv`) is active, then install the official Python build tool:

```
pip install build
```

**Step 3: Build the Package**

Run the compiler at the root of your project to generate the distribution files:

```
python3 -m build
```

**Step 4: Relocate the Wheel File**

The `.whl` file must be located at the root of your Git repository. Move it there using the following command:

```
mv dist/mazegen-1.0.0-py3-none-any.whl .
```

### 🚀 Usage

To install the generated package in any environment, run:

```
pip install mazegen-1.0.0-py3-none-any.whl
```

### Quick Start & Basic Example

Here is a minimal example showing how to import, instantiate, and use the generator in any Python script:

```python
from mazegen import Maze, Dimension, Coordinate

# 1. Define custom parameters
dimensions = Dimension(width=20, height=15)
entrance_cell = Coordinate(0, 0)
exit_cell = Coordinate(19, 14)

# 2. Instantiate the generator (with optional seed for reproducibility)
maze = Maze(
    dim=dimensions,
    entry=entrance_cell,
    exit=exit_cell,
    seed=42,
    perfect=True
)

# 3. Access the generated structure
maze.board          # Board object holding the grid of Box cells (walls, blocked state)
maze.dimension       # Dimension(width, height)
maze.entry           # Coordinate of the entry cell
maze.exit            # Coordinate of the exit cell

# 4. Access the solution
maze.shortest_sol    # list[Direction] — shortest path from entry to exit,
                      # e.g. [Direction.EAST, Direction.EAST, Direction.SOUTH, ...]

# 5. Export to a file (optional)
maze.export("maze.txt")  # writes the hex-encoded maze + entry/exit/solution
```
**Custom parameters** accepted by `Maze()`:

| Parameter | Type | Description |
|---|---|---|
| `dim` | `Dimension` | Width and height of the maze in cells |
| `entry` | `Coordinate` | Starting cell |
| `exit` | `Coordinate` | Target cell |
| `seed` | `int \| float \| str \| bytes \| None` | Optional seed for reproducible generation |
| `perfect` | `bool` | `True` for a single-path maze, `False` to add extra loops |
| `logo` | `AreaLogo \| None` | Optional pattern (e.g. the "42" logo) stamped into the board |


**Accessing the maze structure**: `maze.board` exposes a `Board` object, which holds a grid of `Box` cells. 
Each `Box` stores its wall configuration as a bitmask (see [Output File Format](#output-file-format) 
for the bit meaning) and whether it is blocked (reserved by a logo pattern). 
This internal structure is **not the same format** as the exported output file — use `maze.export(filename)` 
if you need the file-based hex representation.

**Accessing the solution**: `maze.shortest_sol` returns the shortest entry→exit path as a list of `Direction`
 values (computed via BFS at generation time), independent of whether you export the maze to a file.


## Team & Project Management

### Team members

| Login | Role |
|---|---|
| smilitar | Project structure setup |
| | Configuration file parsing and exception handling |
| | Window (MLX) visualizer |
| | Integration of all modules |
| igarcia- | `mazegen` package (maze generation logic) |
| | Terminal visualizer |

### Planning

We split the work by area of expertise: igarcia- took on maze generation — the algorithmic core of the project — while smilitar handled configuration parsing, error handling, and the visualizers. This division let us work in parallel from the start instead of blocking on a single shared module.

As the project evolved, the split became less rigid: we regularly reviewed and adjusted each other's code, and igarcia- later picked up the terminal visualizer as a bonus feature once the core maze generation was stable.

### What worked well

Working on separate modules in parallel let us move fast without stepping on each other's code. Regular check-ins meant issues (like the config/output format mismatches we found while testing with `maze_analyzer.py`) were caught and fixed quickly rather than piling up until the end.

### What could be improved

Communication around interfaces (e.g. matching Board/Maze the exact output format expected by validation tools) could have started earlier — a few small format mismatches surfaced late and cost debugging time. Agreeing on data formats up front, before implementation, would have saved some rework.

## Tools used

- Python 3.10+
- MLX (MinilibX graphical library)
- flake8, mypy (code quality)
- Git (version control)

## Resources

- Python official documentation
- Maze generation algorithms – Jamis Buck's blog
- Graph theory and spanning trees – Wikipedia
- Randomized DFS maze generation – Wikipedia
- MLX documentation – 42 minilibx-linux

### AI usage

AI (Claude, Gemini) was used for the following tasks:

- Setting up the project structure (Makefile, requirements, README skeleton)
- Explaining MLX installation and usage
- Understanding of DFS and shortest path algorithms
- Reviewing code snippets and suggesting improvements

All AI-generated content was reviewed, tested, and validated by the team before inclusion in the project.


## License

This project is licensed under the MIT License — see [LICENSE.md](./LICENSE.md) for details.

## Bonus

- Choice between terminal or graphical (MLX) window visualizer
- Terminal visualization
  - Terminal: step-by-step animation of the maze creation
  - Terminal: step-by-step animation of the solution path being drawn

  In order to visualize the animation in the terminal screen we need to create all the walls between rows and cols.
- Window: ability to regenerate ENTRY/EXIT colours
- Window: ability to regenerate LOGO colours
- Window: displaying the SEED used for the current maze in the graphical window.
- If the PERFECT flag is not activated (the default), the maze must instead be a board directly usable by a Pac-Man-like game. Concretely:
  - every corridor is reachable (full connectivity), so the whole board can be filled with pac-gums and remains winnable;
  - the four corners and the centre are open corridors (the ghosts and super-pacgums sit in the corners, the player starts in the centre);
  - it offers at least two independent routes (loops), so that a chased player always has an alternative (a perfect maze, or a perfect maze with merely one wall removed (a single loop), is therefore not acceptable in this mode);
  - dead-ends should stay rare (a couple are tolerated); a board with no dead-end at all is the ideal and is rewarded as a bonus (see the Bonuses chapter).
- The Window/Terminal will not render if the dimensions surpass the predermined values(~ max size window of the computer)
  - MAX_WIDTH_WINDOW = 126
  - MAX_HEIGHT_WINDOW = 51
  - MAX_WIDTH_TERMINAL = 105
  - MAX_HEIGHT_TERMINAL = 24