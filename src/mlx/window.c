/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:28:55 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 14:29:16 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit_error(t_data *data)
{
	if (!data)
		exit(EXIT_FAILURE);
	if (data->mlx)
	{
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(EXIT_FAILURE);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	my_pixel_put(t_img img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || !img.addr)
		return ;
	dest = img.addr + (y * img.linelen + x * (img.bpp / 8));
	*(unsigned int *) dest = color;
}

void	mlx_loop_helper(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, keyhandler, data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_loop(data->mlx);
}

void	init_window_and_display(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img.img = NULL;

	data->mlx = mlx_init();
	if (!data->mlx)
		exit (EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->win)
		return (mlx_destroy_display(data->mlx), free(data->mlx));
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
		return (mlx_destroy_window(data->mlx, data->win), \
			mlx_destroy_display(data->mlx), free(data->mlx));
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
		&data->img.linelen, &data->img.endian);
}
