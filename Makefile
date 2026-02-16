# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abita <abita@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 14:58:16 by abita             #+#    #+#              #
#    Updated: 2026/02/16 19:46:54 by abita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR   = inc/Libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I inc -I $(LIBFT_DIR)

LIBS = -lmlx -lX11 -lXext -lm

SRC_DIR     = src
OBJ_DIR     = obj

GREEN = \033[0;32m
RESET = \033[0m

SRCS = \
	  main.c \
	  map.c \
	  mlx/keys.c \
	  mlx/window.c \
	  utils/init.c \
	  utils/error_return.c \
	  utils/map_helpers.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ==========================
# Build rules
# ==========================

all: $(LIBFT) $(NAME)
	@echo "$(GREEN)Building Cub3D...$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/cub.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)


$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR) all

# ==========================
# Clean rules
# ==========================

clean:
	@echo "$(GREEN)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(GREEN)Full clean...$(RESET)"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(GREEN)Rebuilding done...$(RESET)"

.PHONY: all debug clean fclean re
.SILENT: