/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:15:08 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 19:03:24 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

// coloring error
# define RED "\033[31m"
# define RESET_COLOR "\033[0m"

// scaling
# define WIDTH 400
# define HEIGHT 400

// arrow keys
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

// escape keys
# define ESC 65307

// map
# define WALL '1'
# define SPACE '0'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

/* ************************************************************************** */
/*                                   ENUM Error FD                            */
/* ************************************************************************** */
typedef enum e_return_values
{
	ERROR_FD = -1,
	ERROR_OPENING_FILE = -2
}			e_return_values;

/* ************************************************************************** */
/*                                   MLX Struct                               */
/* ************************************************************************** */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		linelen;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_data
{
	t_img	img;
	void	*mlx;
	void	*win;
	int		i;

}			t_data;

/* ************************************************************************** */
/*                                   FD				                           */
/* ************************************************************************** */
typedef struct s_line
{
	char	*first_map_line;
	char	*last_map_line;
	int		is_first_line;
	int		error;
	char	*tmp;
}			t_line;

/* ************************************************************************** */
/*                                   MLX Window                               */
/* ************************************************************************** */

void		init_window_and_display(t_data *data);
void		my_pixel_put(t_img img, int x, int y, int color);
void		mlx_loop_helper(t_data *data);
int			keyhandler(int key, t_data *data);
int			ft_exit(t_data *data);
int			ft_exit_error(t_data *data);

/* ************************************************************************** */
/*                                  Utils                                     */
/* ************************************************************************** */

void		print_error(const char *msg);
void		initialize_line(t_line *line);
int			is_all_ones(char *last_map_line);
int			is_valid_row(char *line);
int			is_valid_map_char(char *line);
int			valid_input(char line);

/* ************************************************************************** */
/*                                  MAP                                     */
/* ************************************************************************** */

int			open_file(char *path, t_line *line);
int			validate_map_borders(t_line *line);
void		process_map_line(char *next_line, t_line *line);

#endif