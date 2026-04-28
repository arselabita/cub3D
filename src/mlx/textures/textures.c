/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:04:38 by milija-h          #+#    #+#             */
/*   Updated: 2026/04/28 12:25:02 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

static int	pixel_from_texture(t_texture *texture, int tex_x, int tex_y)
{
	char	*pixel;
	int		value;

	pixel = texture->addr + (tex_y * texture->line_len
			+ tex_x * (texture->bpp / 8));
	ft_memcpy(&value, pixel, sizeof(int));
	return (value);
}

static t_texture	*get_texture(t_data *data)
{
	t_player	*p;

	p = data->player;
	if (p->side == 0)
	{
		if (p->step_x > 0)
			return (&data->texture[2]);
		return (&data->texture[3]);
	}
	else
	{
		if (p->step_y > 0)
			return (&data->texture[1]);
		return (&data->texture[0]);
	}
}

static void	init_tex_column(t_data *data, int wall_height)
{
	data->text_column->texture = get_texture(data);
	data->text_column->draw_start = (HEIGHT / 2) - wall_height;
	if (data->text_column->draw_start < 0)
		data->text_column->draw_start = 0;
	data->text_column->draw_end = (HEIGHT / 2) + wall_height;
	if (data->text_column->draw_end >= HEIGHT)
		data->text_column->draw_end = HEIGHT - 1;
	data->text_column->texture_x = (int)(data->player->wall_x
			* data->text_column->texture->width);
	if ((data->player->side == 0 && data->player->ray_dir_x < 0)
    	|| (data->player->side == 1 && data->player->ray_dir_y > 0))
		data->text_column->texture_x = data->text_column->texture->width
			- data->text_column->texture_x - 1;
	data->text_column->step = (float)data->text_column->texture->height / (wall_height * 2);
	data->text_column->texture_position = (data->text_column->draw_start
			- HEIGHT / 2 + wall_height) * data->text_column->step;
}

void	draw_textured_column(t_data *data, int ray_col, int wall_height)
{
	int	tex_y;

	init_tex_column(data, wall_height);
	while (data->text_column->draw_start < data->text_column->draw_end)
	{
		tex_y = (int)data->text_column->texture_position % data->text_column->texture->height;
		if (tex_y < 0)
		{
			printf("tex_y is not valid\n");
			exit (1);
		}
		data->text_column->texture_position += data->text_column->step;
		my_pixel_put(data->img, ray_col, data->text_column->draw_start,
			pixel_from_texture(data->text_column->texture, data->text_column->texture_x,
				tex_y));
		data->text_column->draw_start++;
	}
}
