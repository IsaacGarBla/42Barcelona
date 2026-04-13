# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: didguill <didguill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 10:41:22 by didguill          #+#    #+#              #
#    Updated: 2026/03/24 21:04:18 by didguill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRC = main.c \
	  parse/parse_map.c \
	  solve/solve_map.c \
	  print/print_map.c \
	  utils/read_file.c \
	  utils/utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/parse
	mkdir -p $(OBJ_DIR)/solve
	mkdir -p $(OBJ_DIR)/print
	mkdir -p $(OBJ_DIR)/utils

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
