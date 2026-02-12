/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:15:08 by abita             #+#    #+#             */
/*   Updated: 2026/02/12 14:49:07 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include "Libft/libft.h"

// coloring error
# define RED         "\033[31m"
# define RESET_COLOR "\033[0m"

// scaling
# define WIDTH  400
# define HEIGHT 400

// arrow keys
# define LEFT  65361
# define UP    65362
# define RIGHT 65363
# define DOWN  65364

// escape keys
# define ESC   65307

// map
# define WALL  '1'
# define SPACE '0'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST  'E'
# define WEST  'W'

typedef enum e_return_values
{
	ERROR_FD = -1,
	ERROR_OPENING_FILE = -2
} e_return_values;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		linelen;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_img		img;
	void		*mlx;
	void		*win;
	int			i;

}	t_data;

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
void	print_error(const char *msg);


#endif