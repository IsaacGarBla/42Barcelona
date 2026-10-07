# Libft

This project was created as a part of the 42 curriculum by [igarcia-](mailto:igarcia-@student.42barcelona.com).

## Description

This project is the implementation of the `libft` library, which is the first project of the Common Core at 42. It contains a set of general-purpose functions that are highly useful for future projects in the curriculum. 

Specifically, the library includes three main groups of functions:

### 1. Standard C Library Functions
A set of functions that replicate the behavior of the original C standard library functions (use `man` to understand their behavior).

* **Memory management:** `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`
* **String manipulation:** `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup`
* **Character checks & conversions:** `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`
* **Type conversion:** `atoi`

### 2. Additional Functions
A set of custom functions to simplify string manipulation, memory management, and file descriptor operations:

* `char *ft_substr(char const *s, unsigned int start, size_t len);`
  * Returns a substring from string `s` that starts at index `start` and has a maximum length of `len`.
* `char *ft_strjoin(char const *s1, char const *s2);`
  * Returns a new string resulting from the concatenation of `s1` and `s2`.
* `char *ft_strtrim(char const *s1, char const *set);`
  * Returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end.
* `char **ft_split(char const *s, char c);`
  * Returns an array of strings obtained by splitting `s` using the character `c` as a delimiter.
* `char *ft_itoa(int n);`
  * Returns a string representing the integer `n`.
* `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`
  * Applies the function `f` to each character of the string `s` to create a new string.
* `void ft_striteri(char *s, void (*f)(unsigned int, char *));`
  * Applies the function `f` to each character of the string `s`, modifying it in place.
* `void ft_putchar_fd(char c, int fd);`
  * Outputs the character `c` to the given file descriptor.
* `void ft_putstr_fd(char *s, int fd);`
  * Outputs the string `s` to the given file descriptor.
* `void ft_putendl_fd(char *s, int fd);`
  * Outputs the string `s` to the given file descriptor followed by a newline.
* `void ft_putnbr_fd(int n, int fd);`
  * Outputs the integer `n` to the given file descriptor.

### 3. Bonus Functions (List Manipulation)
A set of functions for working with singly linked lists based on the following node structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

* `t_list *ft_lstnew(void *content);`
  * Allocates and returns a new node.
* `void ft_lstadd_front(t_list **lst, t_list *new);`
  * Adds the node `new` at the beginning of the list.
* `int ft_lstsize(t_list *lst);`
  * Counts the number of nodes in a list.
* `t_list *ft_lstlast(t_list *lst);`
  * Returns the last node of the list.
* `void ft_lstadd_back(t_list **lst, t_list *new);`
  * Adds the node `new` at the end of the list.
* `void ft_lstdelone(t_list *lst, void (*del)(void *));`
  * Deletes a single node and frees its content using the `del` function.
* `void ft_lstclear(t_list **lst, void (*del)(void *));`
  * Deletes and frees the given node and all its successors.
* `void ft_lstiter(t_list *lst, void (*f)(void *));`
  * Iterates over the list and applies the function `f` to the content of each node.
* `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`
  * Iterates over a list and applies `f` to create a new list. Deletes the new list using `del` if an allocation fails.

## Instructions

### Compilation
You can compile the library using the provided `Makefile`:

```bash
# To compile the mandatory functions
make

# To compile the bonus list functions
make bonus
```

### Usage
To use this library in your code, include the header file:

```c
#include "libft.h"
```

When compiling your project, link it with the compiled library file (`libft.a`):

```bash
gcc main.c -L. -lft -o my_program
```

## Resources

During the development of this project, AI was utilized to better understand the behavior of the original C library functions in Part 1.

## Additional Projects Integrated into Libft

### 4. ft_printf
This project is a custom implementation of the standard `printf` function from the C library (`stdio.h`). The goal is to master variadic arguments in C (`va_start`, `va_arg`, `va_copy`, `va_end`) and structured output formatting.

The function handles the following conversion specifiers:
* `%c` - Prints a single character.
* `%s` - Prints a string of characters.
* `%p` - Prints the memory address of a pointer in hexadecimal format.
* `%d` / `%i` - Prints a signed base 10 integer.
* `%u` - Prints an unsigned base 10 integer.
* `%x` - Prints a hexadecimal number in lowercase.
* `%X` - Prints a hexadecimal number in uppercase.
* `%%` - Prints a single percent sign.

#### Flag Compatibility Matrix
To better understand how the different flags interact with each conversion specifier, refer to the matrix below:

| Flag | `%c` | `%s` | `%p` | `%d` / `%i` | `%u` | `%x` / `%X` |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **`-`** | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| **`0`** | ❌ | ❌ | ❌ | ✅ | ✅ | ✅ |
| **`.`** | ❌ | ✅ | ❌ | ✅ | ✅ | ✅ |
| **`#`** | ❌ | ❌ | ❌ | ❌ | ❌ | ✅ |
| **`+`** | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |
| **`(space)`** | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |

#### Prototype
```c
int ft_printf(char const *format, ...);
```

---

### 5. get_next_line
This project is an implementation of a function that reads a line from a file descriptor (`fd`), ending with a newline character (`\n`) or EOF (End Of File). The main objective is to master static variables, dynamic memory allocation, and efficient file buffer management.

#### Key Features
* **Buffer Management:** Reads data in chunks using a configurable `BUFFER_SIZE` macro defined at compilation time.
* **Static Memory:** Utilizes a static variable to retain remaining data between consecutive function calls.
* **Multi-fd Support:** Capable of managing multiple file descriptors simultaneously without losing the reading thread of any of them.

#### Prototype
```c
char *get_next_line(int fd);
```

---

## Instructions

### Compilation
You can compile the entire extended library using the provided `Makefile`:

```bash
# To compile mandatory, bonus, ft_printf, and get_next_line functions
make
```

### Usage
Since both projects have been integrated into `libft`, you only need to include a single header file in your code:

```c
#include "libft.h"
```

When compiling your project, link it with your unified library file (`libft.a`):

```bash
gcc main.c -L. -lft -o my_program
```

You can also specify the buffer size for `get_next_line` during compilation if needed:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c -L. -lft -o my_program
```
