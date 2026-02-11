# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abita <abita@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 21:32:48 by abita             #+#    #+#              #
#    Updated: 2026/02/11 20:01:33 by abita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

HEADER := libft.h

PRINTF := ft_printf
PRINTF_BINARY := $(PRINTF)/libftprintf.a

OBJ_DIR := printf_obj

AR              := ar rcs
RM              := rm -f
RMDIR           := rm -rf
MKDIR           := mkdir -p

GREEN = \033[0;32m
RESET = \033[0m

CFILES = \
	ft_atof.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
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
	ft_putnbr_fd.c \
	ft_atof.c \
	ft_strcmp.c \
	ft_isspace.c \
	get_next_line.c

OFILES = $(CFILES:.c=.o)


all: $(NAME)
	@echo "$(GREEN)Building Libft...$(RESET)"

$(NAME): $(OFILES)
	@$(AR) $(NAME) $(OFILES)
	@$(MAKE) -s -C $(PRINTF)
	@$(MKDIR) $(OBJ_DIR)
	@cd $(OBJ_DIR) && ar -x ../$(PRINTF_BINARY)
	@$(AR) $(NAME) $(OBJ_DIR)/*.o
	@$(RMDIR) $(OBJ_DIR)


clean:
	@echo "$(GREEN)Cleaning object files...$(RESET)"
	@$(RM) $(OFILES)
	@$(MAKE) -s -C $(PRINTF) clean
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@echo "$(GREEN)Full clean...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(PRINTF) fclean

re: fclean all
	@echo "$(GREEN)Rebuilding done...$(RESET)"

.PHONY: all clean fclean re
.SILENT:
