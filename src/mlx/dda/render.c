/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:00:57 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/17 13:18:04 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000.0) + (time.tv_usec / 1000.0));
}

void	render_frame(t_data *data, t_line *map, t_player *player)
{
	int	x;

	x = 0;
	ft_memset(data->img.addr, 0, HEIGHT * data->img.linelen);
	while (x < WIDTH)
	{
		camera_position(player, x);
		exact_position_in_cell(player);
		distance_to_next_tile(player);
		define_step_len(player);
		advance_to_next_grid(player, map->grid);
		perpendicular_wall_distance(player);
		contact_position(player);
		texture_column(player, 64);
		draw_wall_strip(data, player, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	render_loop(void *param)
{
	t_data			*data;
	static			double	old_time = 0;
	double			time;
	double			frame_time;

	data = (t_data *)param;
	time = get_time_in_ms(); 
	frame_time = (time - old_time) / 1000.0;
	old_time = time;
	update_player(data->player, data->line->grid, frame_time);
	render_frame(data, data->line, data->player);
	return (0);
}
