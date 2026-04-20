/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:52:18 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/13 20:12:24 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_square(t_data *data, float position_x, float position_y,
					size_t tile_size, int color)
{
	size_t	x;
	size_t	y;
	float	pixel_x;
	float	pixel_y;

	y = 0;
	while (y < tile_size)
	{
		x = 0;
		while (x < tile_size)
		{
			pixel_x = position_x + x;
			pixel_y = position_y + y;
			my_pixel_put(data->img, pixel_x, pixel_y, color);
			x++;
		}
		y++;
	}
}

static void	draw_map(t_data *data, char **map)
{
	size_t	y;
	size_t	x;
	char	c;
	int		color;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c == '1')
				color = 0x00FF00;
			else
				color = 0xFFFFFF;

			draw_square(data, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, color);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_data *data, t_player *player, int tile_size)
{
	int	px;
	int	py;
	int	dx;
	int	dy;

	px = (int)(player->pos_x * tile_size);
	py = (int)(player->pos_y * tile_size);
	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			my_pixel_put(data->img, px + dx, py + dy, 0xFF0000);
			dy++;
		}
		dx++;
	}
}

static void	draw_player_direction(t_data *data, t_player *player, int tile_size)
{
	float	step;
	float	max_length;
	float	cur_x;
	float	cur_y;
	int		screen_x;
	int		screen_y;

	step = 0.1f;
	max_length = 2.0f;
	while (step < max_length)
	{
		cur_x = player->pos_x + player->dir_x * step;
		cur_y = player->pos_y + player->dir_y * step;
		screen_x = (int)(cur_x * tile_size);
		screen_y = (int)(cur_y * tile_size);
		my_pixel_put(data->img, screen_x, screen_y, 0x000000);
		step += 0.1f;
	}
}

void	render_grid(t_data *data, t_player *player, char **map)
{
	draw_map(data, map);
	draw_player(data, player, TILE_SIZE);
	draw_player_direction(data, player, TILE_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img,
		0, 0);
}
