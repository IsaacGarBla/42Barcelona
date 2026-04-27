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
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gn
```

## Functionality
- **Static Variables**: Uses a static variable to maintain the remainder of the buffer between successive calls.
- **Memory Management**: Carefully handles `malloc` and `free` to prevent memory leaks.
- **Multiple File Descriptors (Bonus)**: The bonus version supports reading from multiple file descriptors simultaneously without losing the reading thread of each.

