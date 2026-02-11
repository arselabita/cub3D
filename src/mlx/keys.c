/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:33:15 by abita             #+#    #+#             */
/*   Updated: 2026/02/11 15:37:41 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


// int	keyhandler(int key, t_data *data)
// {
// 	// t_fractal	*fract;
// 	double		move_speed;
// 	double		step;

// 	// fract = data->fract;
// 	step = 10.0;
// 	move_speed = step / (WIDTH / (SCALE_FACTOR * fract->zoom));
// 	if (key == ESC)
// 		ft_exit(data);
// 	else if (key == LEFT)
// 		fract->move_x -= move_speed;
// 	else if (key == RIGHT)
// 		fract->move_x += move_speed;
// 	else if (key == UP)
// 		fract->move_y -= move_speed;
// 	else if (key == DOWN)
// 		fract->move_y += move_speed;
// 	keyhandler_iter(key, fract);
// 	fract_type(fract);
// 	return (0);
// }