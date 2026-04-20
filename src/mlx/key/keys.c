/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:33:15 by abita             #+#    #+#             */
/*   Updated: 2026/04/17 13:30:59 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	keyhandler(int keycode, void *param)
{
	t_data		*data;
	t_player	*p;

	data = (t_data *)param;
	p = data->player;

	if (keycode == 65362)
		p->key_up = true;
	if (keycode == 65364)
		p->key_down = true;
	if (keycode == 65361)
		p->key_left = true;
	if (keycode == 65363)
		p->key_right = true;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_data		*data;
	t_player	*p;

	data = (t_data *)param;
	p = data->player;
	if (keycode == 65362)
		p->key_up = false;
	if (keycode == 65364)
		p->key_down = false;
	if (keycode == 65361)
		p->key_left = false;
	if (keycode == 65363)
		p->key_right = false;
	return (0);
}
