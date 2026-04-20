# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 14:58:16 by abita             #+#    #+#              #
#    Updated: 2026/04/19 13:51:23 by milija-h         ###   ########.fr        #
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
	  mlx/key/keys.c \
	  mlx/window/window.c \
	  utils/map_utils.c \
	  utils/parse_utils.c \
	  utils/return_utils.c \
	  parser/parser.c \
	  parser/parse_map.c \
	  parser/parse_color.c \
	  parser/parse_texture.c \
	  mlx/init_player/player.c \
	  mlx/grid.c \
	  mlx/dda/dda_utils.c \
	  mlx/dda/dda_loop.c  \
	  mlx/dda/render.c \
	  mlx/dda/render_utils.c \
	  mlx/textures/textures.c \
	  mlx/movement/movement.c \
	  

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ==========================
# Build rules
# ==========================

all: $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/cub.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling Cub3D...$(RESET)"
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
