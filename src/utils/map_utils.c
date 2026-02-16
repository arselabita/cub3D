/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:56:33 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 13:56:58 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int valid_input(char line)
{
	return (line == SPACE || line == WALL || 
			line == NORTH || line == SOUTH || 
			line == EAST || line == WEST || 
			line == ' ' || line == '\t' );
}

int is_valid_map_char(char *line)
{
	// Allowed: 0 1 N S E W (and spaces)
	int i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr(line, valid_input(line[i])))
			return (0);
		i++;
	}
	return (1);			
}

int	is_valid_row(char *line)
{
	int	i;
	int	len;

	if (!line || line[0] == '\0')
		return (0);
	i = 0;
	len = 0;
	while (line[i] && line[i] != '\n')
		i++;
	len = i;
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

void	initialize_line(t_line *line)
{
	line->first_map_line = NULL;
	line->last_map_line = NULL;
	line->is_first_line = 1;
	line->error = 0;
}