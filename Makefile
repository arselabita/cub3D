# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 14:58:16 by abita             #+#    #+#              #
#    Updated: 2026/04/25 14:17:02 by milija-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory
NAME = cub3D

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
LIBS = -lmlx -lX11 -lXext -lm

SRCS = \
	  main.c \
	  mlx/key/keys.c \
	  mlx/window/window.c \
	  utils/map_utils.c \
	  utils/parse_utils.c \
	  utils/return_utils.c \
	  utils/texture_utils.c \
	  parser/parser.c \
	  parser/parse_map.c \
	  parser/parse_color.c \
	  parser/parse_texture.c \
	  mlx/init_player/player.c \
	  mlx/dda/dda_utils.c \
	  mlx/dda/dda_loop.c  \
	  mlx/dda/render.c \
	  mlx/textures/textures.c \
	  mlx/movement/movement.c \
	  mlx/textures/texture_utils.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = inc/Libft
LIBFT = $(LIBFT_DIR)/libft.a

SILENT ?=0
GREEN = \033[0;32m
PURPLE = \033[1;35m
CYAN = \033[0;36m
RED = \033[1;31m
RESET = \033[0m

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@if [ "$(SILENT)" = "0" ]; then echo "$(GREEN)compiling...$(RESET)"; fi
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDLIBS) -o $(NAME)
	@if [ "$(SILENT)" = "0" ]; then  echo "$(GREEN)ready to execute$(RESET)"; fi

clean:
	@if [ "$(SILENT)" = "0" ]; then echo "$(CYAN)deleting object files...$(RESET)"; fi
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@if [ "$(SILENT)" = "0" ]; then echo "$(CYAN)done$(RESET)"; fi
fclean: clean
	@if [ "$(SILENT)" = "0" ]; then echo "$(RED)fully cleaning...$(RESET)"; fi
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@if [ "$(SILENT)" = "0" ]; then echo "$(RED)done$(RESET)"; fi
re:
	@echo "$(GREEN)re(making)...$(RESET)"
	@$(MAKE) SILENT=1 fclean
	@$(MAKE) SILENT=1 all
	@echo "$(GREEN)done, ready to execute again$(RESET)"

.PHONY: all clean fclean re
