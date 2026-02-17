/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:56:33 by abita             #+#    #+#             */
/*   Updated: 2026/02/17 15:26:05 by abita            ###   ########.fr       */
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
