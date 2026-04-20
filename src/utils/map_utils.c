/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:56:33 by abita             #+#    #+#             */
/*   Updated: 2026/04/18 20:16:30 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_valid_input(char line)
{
	return (line == SPACE || line == WALL || line == NORTH || line == SOUTH
		|| line == EAST || line == WEST || line == ' ' || line == '\t');
}
int is_player(char type)
{
	int i;

	i = 0;
	if (type == WEST || type == EAST || type == NORTH || type == SOUTH)
		i = 1;
	else
		i = 0;
	return (i);
}
int	is_valid(char line)
{
	return (line == 'N' || line == 'S' || line == 'E' || line == 'W' || 
		line == '1' || line == '0');
}
int	is_map_line(char *line)
{
	int	i;

	if (!line)
		return (EXIT_FAILURE);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && !is_player(line[i]))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}
char **creating_2d_map(char **old, char *line)
{
	int i;
	char **new;

	i = 0;
	while (old && old[i])
		i++;
	new = (char **)ft_calloc((i + 2), sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i++] = ft_strdup(line);
	new[i] = NULL;
	free(old);
	return (new);
}
