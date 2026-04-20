/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:02:56 by abita             #+#    #+#             */
/*   Updated: 2026/04/18 21:23:54 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

////////////////
// here i validate the first and last rows to check if it
// contains 1 or also spaces,
// if it contains smth else than it frees and displays error,
//	that the map is not valid
////////////////

static int	parse_input(char *line, t_line *map, t_color_data *c_data, t_texture_data *t_data)
{
	int		i;

	i = 0;
	while (line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
	{
		if (map->map_started)
			return (printf("ERROR: empty line in map\n"), EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	// printf("DEBUG line: [%s]\n", &line[i]);
	// printf("DEBUG map_started: %d\n", map->map_started);
	// printf("DEBUG is_texture: %d\n", is_texture_line(&line[i]));
	// printf("DEBUG is_color: %d\n", is_color_line(&line[i]));
	// printf("DEBUG is_map: %d\n", is_map_line(&line[i]));
	if (!map->map_started)
	{
		if (is_texture_line(&line[i]))
		{
			if (parse_texture(&line[i], t_data) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
		}
		else if (is_color_line(&line[i]))
		{
			if (parse_color(&line[i], c_data) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		else if (is_map_line(&line[i]))
			map->map_started = 1;
		else
			return(print_error("ERROR: invalid config line\n"), EXIT_FAILURE);
	}
	if (map->map_started)
	{
		if (map_parsing(&line[i], map) != EXIT_SUCCESS)
			return (printf("ERROR: invalid line after map\n"), EXIT_FAILURE);		
	}
	return (EXIT_SUCCESS);
}

int	parser(char *path, t_line *map, t_color_data *c_data, t_texture_data *t_data)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error("Error: opening the file\n"), ERROR_FD);
	init_line(map);
	while ((line = get_next_line(fd)))
	{
		if (parse_input(line, map, c_data, t_data) != EXIT_SUCCESS)
		{
			free(line);
			get_next_line(-1);
			close(fd);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	get_next_line(-1);
	close(fd);
	if (!map->map_started)
		return (print_error("ERROR: No map found.\n"), EXIT_FAILURE);
	if (grid_validation(map->grid, map->height, map) != EXIT_SUCCESS)
		return (free_split(map->grid), EXIT_FAILURE);
	free_split(map->grid);
	return (EXIT_SUCCESS);
}
