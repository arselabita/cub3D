/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:06:52 by abita             #+#    #+#             */
/*   Updated: 2026/02/19 15:36:02 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_line(t_line *map)
{
	map->first_map_line = NULL;
	map->last_map_line = NULL;
	map->is_first_line = 1;
	map->error = 0;
	map->player_count = 0;
	map->map_started = 0;
}

int	skip_whitespace(char *line)
{
	int i;

	i = 0;
	while ((line[i] && line[i] == ' '))
		i++;
	return (i);
}
int is_texture_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O') 
		|| (line[i] == 'S' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'E' && line[i + 1] == 'A'))
	{
		if (line[i + 2] == ' ' || line[i + 2] == '\t')
			return (1);
	}
	return (0);
} 

int is_color_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'F' || line[i] == 'C')
	{
		if (line[i + 1] == ' ' || line[i + 1] == '\t')
			return (1);
	}
	return (0);
}

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
