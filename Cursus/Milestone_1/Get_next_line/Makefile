NAME = gnl

# Directories
SRC_DIR = ./src
INC_DIR = ./include
SRC_DIR_BONUS = ./src_bonus
INC_DIR_BONUS = ./include_bonus
OBJ_DIR = ./objs
OBJ_DIR_BONUS = ./objs_bonus

MAIN = main_gnl.c
MAIN_BONUS = main_gnl.c

# File sources to compile
MY_SOURCES =	get_next_line.c \
				get_next_line_utils.c

MY_SOURCES_BONUS =	get_next_line_bonus.c \
					get_next_line_utils_bonus.c

# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

SRCS_BONUS	= $(addprefix $(SRC_DIR_BONUS)/, $(MY_SOURCES_BONUS))
OBJS_BONUS	= $(addprefix $(OBJ_DIR_BONUS)/, $(MY_SOURCES_BONUS:.c=.o))

#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra 

all: $(NAME)

#Create the library
$(NAME): $(OBJS) Makefile
		 $(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS) $(SRC_DIR)/$(MAIN) -o $(NAME)

bonus:	$(OBJS_BONUS)
		 $(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS_BONUS) $(SRC_DIR_BONUS)/$(MAIN_BONUS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -I$(INC_DIR) -fPIC -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
		@mkdir -p $(OBJ_DIR_BONUS)
		$(CC) $(CFLAGS) -I$(INC_DIR_BONUS) -fPIC -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		rm -rf $(OBJ_DIR_BONUS)

fclean: clean
		rm -f $(NAME)		

re:	fclean all

.PHONY: all clean fclean re
