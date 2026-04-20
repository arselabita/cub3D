/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:26:01 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/19 14:37:24 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	advance_to_next_grid(t_player *player, char **map)
{
	int	hit;

	//if (player->map_y < 0 || !map[player->map_y])
	//	return;
	//if (player->map_x < 0 || !map[player->map_y][player->map_x])
	//	return;
	hit = 0;
	while (hit == 0)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (map[player->map_y][player->map_x] == '1')
			hit = 1;
	}
}

void	perpendicular_wall_distance(t_player *player)
{
	if (player->side == 0)
		player->perp_wall_dist = player->side_dist_x - player->delta_dist_x;
	else
		player->perp_wall_dist = player->side_dist_y - player->delta_dist_y;
}

//translate it: hit_point = player_pos + ray * distance
void	contact_position(t_player *player)
{
	if (player->side == 0)
		player->wall_x = player->pos_y + player->perp_wall_dist
			* player->ray_dir_y;
	else
		player->wall_x = player->pos_x + player->perp_wall_dist
			* player->ray_dir_x;
	player->wall_x -= floor(player->wall_x);
}

void	texture_column(t_player *player, int tex_width)
{
	player->texture_x = (int)(player->wall_x * tex_width);
	if (player->side == 0 && player->ray_dir_x > 0)
		player->texture_x = tex_width - player->texture_x - 1;
	if (player->side == 1 && player->ray_dir_y < 0)
		player->texture_x = tex_width - player->texture_x - 1;
}
