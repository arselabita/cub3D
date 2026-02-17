/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:06:52 by abita             #+#    #+#             */
/*   Updated: 2026/02/17 15:32:43 by abita            ###   ########.fr       */
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
	while ((line[i] && line[i] == ' ') || (line[i] >= 9 && line[i] <= 13))
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
////////////////
// here i validate the first and last rows to check if it
// contains 1 or also spaces,
// if it contains smth else than it frees and displays error,
//	that the map is not valid
////////////////
int	validate_map(t_line *map)
{
	if (map->error)
	{
		print_error("ERROR: Invalid map\n");
		return (EXIT_FAILURE);
	}
	if (!map->first_map_line || !map->last_map_line)
	{
		print_error("ERROR: Empty map.\n");
		return (EXIT_FAILURE);
	}
	if (!is_all_ones(map->first_map_line) || !is_all_ones(map->last_map_line))
	{
		print_error("ERROR: Map not closed.\n");
		return (EXIT_FAILURE);
	}
	if (map->player_count != 1)
	{
		print_error("ERROR: Map should contain only one player.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
