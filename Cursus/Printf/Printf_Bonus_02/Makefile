NAME = libftprintf.a

# Directories
SRC_DIR = ./srcs
INC_DIR = ./includes
OBJ_DIR = ./objs
LIB_DIR = ./lib
LIBFT   = ./libft/libft.a 
LIBFT_DIR = ./libft

# File sources to compile
MY_SOURCES =	ft_printf.c \
				ft_printf_c.c \
				ft_printf_s.c \
				ft_printf_di.c \
				ft_printf_p.c \
				ft_printf_u.c \
				ft_printf_x.c \
				ft_printnbr_f.c \
				ft_putnchar.c
				
# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

#Create the library
$(NAME): $(LIBFT) $(OBJS)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
