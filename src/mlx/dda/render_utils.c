/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:00:49 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/20 15:26:18 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_wall_strip(t_data *data, t_player *player, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
	int	y;

	//printf("perp_wall_dist is: %f\n", player->perp_wall_dist);
	line_height = (int)(HEIGHT / player->perp_wall_dist);
	//printf("line height is: %d\n", line_height);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	//printf("draw_end is: %d\n", draw_end);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (player->side == 0)
		color = 0xA9A9A9;
	else 
		color = 0xFFFFFF;
	y = draw_start;
	//my_pixel_put(data->img, x, HEIGHT / 2, 0xFF0000);
	while (y < draw_end)
	{
		my_pixel_put(data->img, x, y, color);
		y++;
	}
}
