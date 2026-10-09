NAME = libft.a

# Directories
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objs

# File sources to compile
MY_SOURCES = 	ft_putchar.c \
				ft_putstr.c \
				ft_strcmp.c \
				ft_strlen.c \
				ft_swap.c

# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR)

CUR_DIR = $(shell pwd)

all: $(NAME)

#Create the library
$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re:	clean all

