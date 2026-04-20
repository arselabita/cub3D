/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:04:38 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/20 15:23:16 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//img.ptr = mlx_xpm_file_to_image(mlx, "../textures/wall_s.xpm", &img.width, &img.height);
//img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

/*static void	texture_img(t_texture *texture, t_data *data, char *path)
{
	texture->img = mlx_xpm_file_to_image(data->mlx, path, &texture->width,
			&texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian); //texture->img or mlx->img
}

static void	get_texture_directions(t_texture *texture, t_data *data,
			t_texture_data *texture_data)
{
	texture_img(texture, data, texture_data->no);
	texture_img(texture, data, texture_data->so);
	texture_img(texture, data, texture_data->ea);
	texture_img(texture, data, texture_data->we);
}*/

/*void	final_texture(t_player *player, t_texture *texture, t_data *data,
			t_texture_data *texture_data)
{
	int	step;

	step = 0;
}*/