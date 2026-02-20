/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:15:08 by abita             #+#    #+#             */
/*   Updated: 2026/02/20 20:48:43 by abita            ###   ########.fr       */
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
////////////////////////////////////////////////////////////////////////////////
/* ************************************************************************** */
/*                                   ENUM Error FD                            */
/* ************************************************************************** */
typedef enum e_return_values
{
	ERROR = -1,
	ERROR_FD = -2,
	ERROR_OPENING_FILE = -3,
	ERROR_INVALID_MAP = -4
}			e_return_values;

/* ************************************************************************** */
/*                             ENUM Texture Types                             */
/* ************************************************************************** */
typedef enum e_txt_type
{
	NO,
	SO,
	WE,
	EA
}			t_txt_type;

/* ************************************************************************** */
/*                             ENUM Color   Types                             */
/* ************************************************************************** */
typedef enum e_color_type
{
	F = 11,
	C = 12
}			t_color_type;

////////////////////////////////////////////////////////////////////////////////
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
/*                                   FD_line Struct									*/
/* ************************************************************************** */
typedef struct s_line
{
	char	*first_map_line;
	char	*last_map_line;
	int		is_first_line;
	int		error;
	char	*tmp;
	int		player_count;
	int		map_started;
}			t_line;


/* ************************************************************************** */
/*                                   Color Struct                             */
/* ************************************************************************** */

typedef struct s_color_data
{
	int		floor_color;
	int		ceiling_color;
}			t_color_data;


/* ************************************************************************** */
/*                                   Texture Struct	                          */
/* ************************************************************************** */

typedef struct s_texture_data
{
	int no;
	int so;
	int we;
	int ea;
	int fd;
} t_texture_data;


////////////////////////////////////////////////////////////////////////////////
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
int			is_all_ones(char *last_map_line);
int			is_player(char line);
int			is_valid_input(char line);

/* ************************************************************************** */
/*                                  Parser                                    */
/* ************************************************************************** */

int	parser(char *path, t_line *map, t_color_data *c_data, t_texture_data *t_data);

// map //
int			parse_map_line(char *line, t_line *map);
int			is_valid_row(char *line);
int			is_valid_map(char *line, t_line *map);

// textures //
int	parse_texture(char *line, t_texture_data *t_data);

// color //
int			parse_color(char *line, t_color_data *c_data);

// utils //
void		init_line(t_line *line);
int			skip_whitespace(char *line);
int			is_texture_line(char *line);
int			is_color_line(char *line);
void		free_split(char **split);

#endif