NAME = libftprintf.a

# Directories
SRC_DIR = ./srcs
INC_DIR = ./includes
OBJ_DIR = ./objs
LIB_DIR = ./lib

# File sources to compile
MY_SOURCES = 	

MY_SOURCES_BONUS = 	
					

# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

SRCS_BONUS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES_BONUS))
OBJS_BONUS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES_BONUS:.c=.o))


#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR) -L($LIB_DIR) -llibft

all: $(NAME)

#Create the library
$(NAME): $(OBJS)
		 # $(CC) $(CFLAGS) $(OBJS) 
		 ar rcs $(NAME) $(OBJS)

bonus:	$(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)

fclean: clean
		rm -f $(NAME)

re:	clean all

.PHONY: all clean fclean re
