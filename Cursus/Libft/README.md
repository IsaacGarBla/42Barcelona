*This project was created as a part of 42 resume by igarcia-.*

# DESCRIPTION

This project is the implementation of ‘libft’ library, which is the firs project of de Common Core.
It contains a set of functions that can be useful for future projects. Specifically, it includes three group of functions:

1. A set of functions that reply the behavior of the original C functions (see ‘man’ to understand its behavior).

isalpha
isdigit
isalnum
isascii
isprint
strlen
memset
bzero

memcpy
memmove
strlcpy
strlcat
toupper
tolower
strchr 

strrchr
strncmp
memchr
memcmp
strnstr
atoi

calloc
strdup

2. A set of additional functions:

*char *ft_substr(char const *s, unsigned int start, size_t len);*
Returns a sub string of s that starts in ‘start’ and has a max long of ‘len’.

*char *ft_strjoin(char const *s1, char const *s2);*
Returns a new strig joining s1 and s2.

*char *ft_strtrim(char const *s1, char const *set);*
Returns a copy of s1, erasing the characters of set a the beginning and the end of s1.

*char **ft_split(char const *s, char c);*
Returns and array of strings as a result of splitting the string ‘s’ using the char ‘c’ as a delimiter.

*char *ft_itoa(int n);*
Returns an string that represents de integer n.

*char *ft_strmapi(char const *s, char (*f)(unsigned int, char));*
Returns an string a a result of apply the function ‘f’ to each char of ‘s’, passing to ‘f’ de char positions and the char itself.

*void ft_striteri(char *s, void (*f)(unsigned int, char*));*
Modifies the string s applying the function ‘f’ to each char of ‘s’.

*void ft_putchar_fd(char c, int fd);*
Sends the char ‘c’ to the file descriptor ‘fd’.

*void ft_putstr_fd(char *s, int fd);*
Sends the string ‘s’ to the file descriptor ‘fd’.

*void ft_putendl_fd(char *s, int fd);*
Sends the string ‘s’ to the file descriptor ‘fd’ followed by a new line.

*void ft_putnbr_fd(int n, int fd);*
Writes the integer ‘n’ to the file descriptor ‘fd’.

3. A set of functions for working with list based on the following node:

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

*t_list *ft_lstnew(void *content);*
Returns a pointer to a new created node.

*void ft_lstadd_front(t_list **lst, t_list *new);*
Adds the node ‘new’ at the begging of the list ‘lst’.

*int ft_lstsize(t_list *lst);*
Returns the number of nodes in the list ‘lst’.

*t_list *ft_lstlast(t_list *lst);*
Returns the last node in the list ‘lst’.

*void ft_lstadd_back(t_list **lst, t_list *new);*
Adds the node ‘new’ at the end of the list ‘lst’.

*void ft_lstdelone(t_list *lst, void (*del)(void *));*
Releases the content and the node ‘lst’ itself.

*void ft_lstclear(t_list **lst, void (*del)(void *));*
Releases the content and the nodes themselves of the list ‘lst’.

*void ft_lstiter(t_list *lst, void (*f)(void *));*
Iterates over all the nodes of the list ‘lst’ and applies the function ‘f’ to the content of each node.

*t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));*
Iterates over all the nodes of the list ‘lst’ and creates a new list applying the function ‘f’ to the content of each node in ‘lst’ to create the new node. If there is any error, releases the new list applying the function ‘del’ to the content of each node.

# INSTRUCCIONS		

You can compile the library using de utility make with de provided ‘Makefile’.
To use this library, you must include the file ‘libft.h’ in your code and when compiling, link your code with this library.

Also, you can use the rules *clean* (erases all the object files), *fclean* (erases, also, the library file) and *re* (executes the rule clean and creates the library again).

# RESOURCES

During the developing of this project, I've mostly used *man* and google. Also, the IA has been used to better understand the behavior of the original C functions in part 1.
