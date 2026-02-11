# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abita <abita@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 20:55:11 by abita             #+#    #+#              #
#    Updated: 2026/02/11 15:23:27 by abita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = \
		ft_printf.c ft_putstr.c ft_putnbr.c \
		ft_putnbr_u.c ft_putchar.c ft_hexadecimal.c ft_hexadecimal_pointer.c \
		ft_hexadecimal_upper.c ft_calloc.c ft_bzero.c ft_strlen.c

OFILES = $(CFILES:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
		ar rcs $(NAME) $(OFILES)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: $(NAME)
	$(CC) ft_printf.c libftprintf.a -o ./run.out
	./run.out

.PHONY: all clean fclean re
SILENT: