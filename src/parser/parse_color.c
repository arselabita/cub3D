/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:00:00 by abita             #+#    #+#             */
/*   Updated: 2026/02/19 14:11:31 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}


int get_id_type(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'F')
		return (F);
	if (line[i] == 'C')
		return (C);
	return (ERROR);
}

int get_color_range(char *line)
{
	int i;
	int j;
	char **split;
	int	rgb[3];

	i = 0;
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	i += 1;
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	split = ft_split(line + i, ',');
	if (!split)
		return (free_split(split), -1);
	j = 0;
	while (j < 3)
	{
		if (!split[j])
			return (-1);
		rgb[j] = atoi(split[j]);
		if (rgb[j] < 0 || rgb[j] > 255)
			return (free_split(split), -1);
		j++;
	}
	if (split[3])
		return(free_split(split), -1);
	return (free_split(split), RGB); // pass the rgb bit shifting
}

int parse_color(char *line, t_color_data *c_data)
{
	int id;
	int color;
	t_color_data c_data;

	id = get_id_type("F 220,100, 0");
	if (id == -1)
		return (-1); // error
	printf("the texture is: %i\n", id);
	color = get_color_range(line);
	if (color == -1)
		return (-1); // error
	if (id == F)
		c_data->floor_color = color;
	if (id == C)
		c_data->ceiling_color = color;
	return (EXIT_SUCCESS);
}