/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:56:33 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 19:59:19 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_valid_input(char line)
{
	return (line == SPACE || line == WALL || line == NORTH || line == SOUTH
		|| line == EAST || line == WEST || line == ' ' || line == '\t');
}
int	is_player(char line)
{
	return (line == NORTH || line == SOUTH || line == EAST || line == WEST);
}
/// 
// here i just validate if within the map we have
// Allowed: 0 1 N S E W (and spaces)
/// 
int	is_valid_map_char(char *line, t_line *map)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_input(line[i]))
			return (0);
		if (is_player(line[i]))
			map->player_count++;
		i++;
	}
	return (1);
}

int	is_valid_row(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[0] != WALL)
		return (0);
	if (line[len - 1] != WALL)
		return (0);
	return (1);
}

int	is_all_ones(char *last_map_line)
{
	int	i;

	i = 0;
	while (last_map_line[i])
	{
		if (last_map_line[i] != WALL && !ft_isspace(last_map_line[i]))
			return (0);
		i++;
	}
	return (1);
}
