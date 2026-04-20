/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:19:46 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/17 13:22:44 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//our game works on a frame per second (image rendered per second) basis, so
//to enable the movement to be smooth in both slow and fast computers, we have
// to compute the time it takes for each frame to be drawn.
// 
// So each frame: movement_this_frame = speed_per_second * frame_time
//it also helps us with the rotation, we will rotate movement_this_frame each time

void	compute_speed(t_player *p, double frame_time)
{
	p->move_speed = frame_time * 5.0;
	p->rot_speed = frame_time * 3.0;
}

void	move_forward_backward(t_player *p, double move_speed, char **map, int dir)
{
	double	new_x;
	double	new_y;

	new_x = p->pos_x + p->dir_x * move_speed * dir;
	new_y = p->pos_y + p->dir_y * move_speed * dir;
	if (map[(int)p->pos_y][(int)new_x] != '1')
		p->pos_x = new_x;
	if (map[(int)new_y][(int)p->pos_x] != '1')
		p->pos_y = new_y;
}

//turn player left of right
void	rotate_player(t_player *p, double rot_speed, int dir)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = rot_speed * dir;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

void	update_player(t_player *p, char **map, double frame_time)
{
	compute_speed(p, frame_time);
	if (p->key_up)
		move_forward_backward(p, p->move_speed, map, 1);
	if (p->key_down)
		move_forward_backward(p, p->move_speed, map, -1);
	if (p->key_left)
		rotate_player(p, p->rot_speed, -1);
	if (p->key_right)
		rotate_player(p, p->rot_speed, +1);
}
