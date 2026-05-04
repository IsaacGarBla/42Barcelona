NAME = push_swap

# Directories
SRC_DIR		= ./src
INC_DIR		= ./include
BUILD_DIR	= ./build
OBJ_DIR		= $(BUILD_DIR)/obj
LIB_DIR		= ./lib

# File sources to compile
MY_SOURCES =	main.c \
				init_data.c \
				parse_input.c \
				dispatch_strategy.c \
				utils.c \
				stack/stack_1.c \
				stack/stack_2.c \
				stack/stack_3.c

# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR)
LDFLAGS     = -L$(LIB_DIR)
LDLIBS      = -lftprintf


all: $(NAME)

#Create the files and directories needed to compile the program
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
		rm -rf $(BUILD_DIR)

fclean: clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
