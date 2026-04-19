NAME = libft.a

# Directories
SRC_DIR = .
INC_DIR = .
OBJ_DIR = .

# File sources to compile
MY_SOURCES = 	ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

MY_SOURCES_BONUS = 	ft_lstadd_front_bonus.c \
					ft_lstnew_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c
					

# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

SRCS_BONUS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES_BONUS))
OBJS_BONUS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES_BONUS:.c=.o))


#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR)

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
