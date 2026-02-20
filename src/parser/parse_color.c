/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:00:00 by abita             #+#    #+#             */
/*   Updated: 2026/02/20 22:47:13 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_number(char *n)
{
	int	i;

	if (!n || !n[0])
		return (0);
	i = 0;
	while (n[i] == ' ' || n[i] == '\t')
		i++;
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	get_id_type(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (F);
	if (line[i] == 'C' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (C);
	return (ERROR);
}

static int	get_color_range(char *line)
{
	int		i;
	int		j;
	char	**split;
	int		rgb[3];
	int		color;
	int		comma;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i += 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma == 3)
		return (-1);
	char *trim = ft_strtrim(&line[i], "\n \t");
	if (!trim)
		return (-1);
	split = ft_split(trim, ',');
	if (!split)
		return (free(trim), free_split(split), -1);
	j = 0;
	while (j < 3)
	{
		if (!split[j] || !is_number(split[j]))
			return (free(trim), free_split(split), -1);
		rgb[j] = ft_atoi(split[j]);
		if (rgb[j] < 0 || rgb[j] > 255)
			return (free(trim), free_split(split), -1);
		j++;
	}
	if (split[3])
		return (free(trim), free_split(split), -1);
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (free(trim), free_split(split), color); // passing the rgb bit shifting
}

int	parse_color(char *line, t_color_data *c_data)
{
	int id;
	int color;

	id = get_id_type(line);
	if (id == ERROR)
		return (-1); // error
	color = get_color_range(line);
	if (color == ERROR)
		return (-1); // error
	if (id == F)
		c_data->floor_color = color;
	if (id == C)
		c_data->ceiling_color = color;
	return (EXIT_SUCCESS);
}