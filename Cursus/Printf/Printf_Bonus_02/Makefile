NAME = libftprintf.a

# Directories
SRC_DIR = ./src
INC_DIR = ./include
SRC_DIR_BONUS = ./src_bonus
INC_DIR_BONUS = ./include_bonus
OBJ_DIR = ./objs
OBJ_DIR_BONUS = ./objs_bonus
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

MY_SOURCES_BONUS = 	ft_printf_bonus.c \
					ft_printf_c_bonus.c \
					ft_printf_s_bonus.c \
					ft_printf_di_bonus.c \
					ft_printf_p_bonus.c \
					ft_printf_u_bonus.c \
					ft_printf_x_bonus.c \
					ft_printnbr_f_bonus.c \
					ft_putnchar_bonus.c

# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

SRCS_BONUS	= $(addprefix $(SRC_DIR_BONUS)/, $(MY_SOURCES_BONUS))
OBJS_BONUS	= $(addprefix $(OBJ_DIR_BONUS)/, $(MY_SOURCES_BONUS:.c=.o))

#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra  -gdwarf-4 -I$(LIBFT_DIR)

all: $(NAME)

#Create the library
$(NAME): $(LIBFT) $(OBJS) Makefile
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

bonus:	$(LIBFT) $(OBJS_BONUS)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS_BONUS)

$(LIBFT):
		make -C $(LIBFT_DIR)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -I$(INC_DIR) -fPIC -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
		@mkdir -p $(OBJ_DIR_BONUS)
		$(CC) $(CFLAGS) -I$(INC_DIR_BONUS) -fPIC -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		rm -rf $(OBJ_DIR_BONUS)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
