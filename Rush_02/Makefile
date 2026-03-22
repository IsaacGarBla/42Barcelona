# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/22 21:38:23 by igarcia-          #+#    #+#              #
#    Updated: 2026/03/22 21:47:14 by igarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = main.c print.c solve.c check.c dictionary.c parse_dict.c solution.c string.c convert.c

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -I. $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(SRC) -I. -c $< -o $@

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean test re
