NAME = ft_display_file

# Directories
SRC_DIR = $(shell pwd)
INC_DIR = includes
OBJ_DIR = objs

# File sources to compile
MY_SOURCES = 	ft_display_file.c

#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR)

all: $(NAME)

$(NAME): 
		$(CC) $(CFLAGS) $(MY_SOURCES) -o $(NAME)
		
clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re:	clean all

