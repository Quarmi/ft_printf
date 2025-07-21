# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irmarqui <irmarqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 16:29:49 by irmarqui          #+#    #+#              #
#    Updated: 2025/07/21 17:24:37 by irmarqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = executable

SRC = ft_printf.c ft_printf_utils.c test_printf.c

OBJS := $(SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
