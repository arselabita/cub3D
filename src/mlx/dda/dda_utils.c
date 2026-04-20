/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:53:46 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/15 17:09:26 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//exact position in the fov line in a normalized way
//instead of working with the with for example a 320 pixels wide screen
//left would be -1 middle 0 right 1
//in this case we are talking about the x-axis (horizontally) strictly
void	camera_position(t_player *player, int x)
{
	player->camera_x = 2.0f * x / (float)WIDTH - 1.0f;
	//printf("camera_x = %f\n", player->camera_x);
	player->ray_dir_x = player->dir_x + player->plane_x
		* player->camera_x;
	//printf("ray_dir_x = %f\n", player->ray_dir_x);
	player->ray_dir_y = player->dir_y + player->plane_y
		* player->camera_x;
	//printf("ray_dir_y = %f\n", player->ray_dir_y);
}

// we we will compute the exact position of our player within the given
//cell, as we know our map is a combination of cell, each with a x and y
//axis position
//what we do here is we try to find the fractional part of the x/y position
// we do that by taking the integer part of the float position and subtracting
//it by its decimal part
void	exact_position_in_cell(t_player *player)
{
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;

	//map should be float or int???
	//printf("map_x = %d\n", player->map_x);
	//printf("map_y = %d\n", player->map_y);
}

//further check where the formula comes from
void	distance_to_next_tile(t_player *player)
{
	//printf("ray_dir_x raw = %f\n", player->ray_dir_x);
	//printf("ray_dir_y raw = %f\n", player->ray_dir_y);
	if (player->ray_dir_x == 0)
		player->delta_dist_x = 1e30;
	else
		player->delta_dist_x = fabs(1.0 / player->ray_dir_x);
	if (player->ray_dir_y == 0)
		player->delta_dist_y = 1e30;
	else
		player->delta_dist_y = fabs(1.0 / player->ray_dir_y);
	//printf("player->delta_dist_x is %f\n", player->delta_dist_x);
	//printf("player->delta_dist_y is %f\n", player->delta_dist_y);
}

//distance of a step is by default 1 or -1
//if its 1, it means we are facing in the direction in which the given axis is
//affected
void	define_step_len(t_player *player)
{	
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->pos_x - player->map_x)
			* player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->pos_x)
			* player->delta_dist_x;
	} 
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->pos_y - player->map_y)
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->pos_y)
			* player->delta_dist_y;
	}
	//printf("player->side_dist_x = %f\n", player->side_dist_x);
	//printf("player->side_dist_y = %f\n", player->side_dist_y);
}