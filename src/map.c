/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:55:41 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 20:04:09 by abita            ###   ########.fr       */
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
void	process_map_line(char *line, t_line *map)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return ;
	if (map->is_first_line)
	{
		map->first_map_line = ft_strdup(&line[i]);
		map->is_first_line = 0;
	}
	free(map->last_map_line);
	map->last_map_line = ft_strdup(&line[i]);
	if (!is_valid_row(&line[i]))
		map->error = 1;
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

int	open_file(char *path, t_line *map)
{
	int		fd;
	char	*next_line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error("Error: opening the file\n"), ERROR_FD);
	printf("opened the file\n"); // DEBUG
	initialize_line(map);
	while ((next_line = get_next_line(fd)))
	{
		printf("%s\n", next_line); // DEBUG
		if (!is_valid_map_char(next_line, map))
		{
			map->error = 1;
			free(next_line);
			break ;
		}
		process_map_line(next_line, map);
		free(next_line);
		if (map->error)
			break ;
	}
	// this bcs inside gnl i use a static var
	// and it causes leaks when i pass invalid map
	get_next_line(-1);
	close(fd);
	if (validate_map(map) != EXIT_SUCCESS)
		return (free(map->first_map_line), free(map->last_map_line),
			EXIT_FAILURE);
	printf("Map validation passed\n"); // DEBUG
	free(map->first_map_line);
	free(map->last_map_line);
	return (EXIT_SUCCESS);
}
