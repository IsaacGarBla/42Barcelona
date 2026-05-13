*This project was create, as a part of 42 resume, by igarcia-.*

# get_next_line


## Introduction
The **get_next_line** project is a fundamental task at 42 school that involves creating a function that returns a line read from a file descriptor. This project introduces the concept of **static variables** in C programming and focuses on efficient memory management and buffer handling.

## Project Requirements
The function must conform to the following prototype:
```c
char *get_next_line(int fd);
```

- Repeated calls to `get_next_line()` should allow reading the entire text content of a file descriptor, one line at a time.
- The function should return the line that was read. If there is nothing else to read or if an error occurred, it should return `NULL`.
- The returned line must include the terminating `\n` character, except if the end of file was reached and does not end with a `\n`.
- The project must compile with the flag `-D BUFFER_SIZE=n`.

## Usage
To use `get_next_line` in your project, include the header and compile the source files:

1. Include the header in your code:
```c
#include "get_next_line.h"
```

2. Compile with your main file (or other files). Example with buffer size 42:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```
I recommend you using the tool `valgrind` to check if you have memory leaks in your code.

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gnl
```

## Bonus Part
The bonus version of the project extends the functionality to handle multiple file descriptors and optimize file structure.

### Requirements
- Manage multiple file descriptors simultaneously. For example, if you read from `fd 3`, then `fd 4`, and then `fd 5`, you can alternate between them without losing the reading thread or the data of any specific `fd`.

- The code must be contained within three specific files:
  - `get_next_line_bonus.c`
  - `get_next_line_bonus.h`
  - `get_next_line_utils_bonus.c`

### Implementation
To achieve this, the static variable is converted into an array of pointers, where the index corresponds to the file descriptor number:

```c
static char *remainder_buffer[MAX_OPEN_FD];
```
*Note: `MAX_OPEN_FD` (typically 1024) or a similar macro ensures that the array can accommodate the maximum number of open files allowed by the system.*

### Bonus Usage
To compile the project using the bonus files, include the bonus header and run the compilation command:

1. Include the bonus header in your code:
```c
#include "get_next_line_bonus.h"
```

2. Compile with the bonus source files:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

3. Run with `valgrind` to ensure multiple file switches do not cause leaks:
```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gnl_bonus
```

## Functionality
- **Static Variables**: Uses a static variable to maintain the remainder of the buffer between successive calls.
- **Memory Management**: Carefully handles `malloc` and `free` to prevent memory leaks.
- **Multiple File Descriptors (Bonus)**: The bonus version supports reading from multiple file descriptors simultaneously without losing the reading thread of each.

