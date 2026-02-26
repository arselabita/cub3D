/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:55:41 by abita             #+#    #+#             */
/*   Updated: 2026/02/24 20:12:02 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

////////////////
// so, literally,
//	what i do is that i created these 2 variables first and last row,
// to keep track in case these rows are other than 1s. They should always
// be 1 nontheless
// so what i do, i check for each char, and if the first_map_line is empty,
// then add only the first line
// in case we have:
// 		00000000
// 		00000000
// 		11111111
// here our first_map_line will be: 00000000
// where as the last_map_line will just be overwritten for each iteration
// until it reaches the end
// and as a result our last_map_line will be: 11111111
////////////////

int	is_valid_map(char *line, t_line *map)
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

int	is_valid_row(char *line, t_line *map)
{
	int	len;
	char **mat;
	(void)map;

	if (!line)
		return (0);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	
/////////////////////////////////////////////////


	mat = ft_split(line, '\n');
	if (!mat)
		return(free(mat), 1);
	
	int N = sizeof(mat) / sizeof(mat[0]);
    int M = sizeof(mat[0]) / sizeof(mat[0][0]);	
	for(int i = 0; i < N * M; i++)
	{
		int row  = i / M;
		int col = i % M;
		printf("%c\n", mat[row][col]);
		free(mat[i]);
	}
	free(mat);	
	// printf("len: %i\n", len);
	// printf("line[%i]: %s\n", len, line);
	if (line[0] != WALL)
		return (0);
	if (line[len - 1] != WALL)
		return (0);
	// printf("last row: %s", map->last_map_line);
	
	return (1);
}

int	parse_map_line(char *line, t_line *map)
{
	int	i;

	i = 0;
	// map->map_started = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (EXIT_SUCCESS);
	if (!is_valid_map(line, map))
	{
		map->error = 1;
		return (ERROR_INVALID_MAP);
	}
	if (map->is_first_line)
	{
		map->first_map_line = ft_strdup(&line[i]);
		map->is_first_line = 0;
	}
	free(map->last_map_line);
	map->last_map_line = ft_strdup(&line[i]);
	if (!is_valid_row(&line[i], map))
		map->error = 1;

	return (EXIT_SUCCESS);
}
