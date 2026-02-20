/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:02:56 by abita             #+#    #+#             */
/*   Updated: 2026/02/19 20:12:56 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

////////////////
// here i validate the first and last rows to check if it
// contains 1 or also spaces,
// if it contains smth else than it frees and displays error,
//	that the map is not valid
////////////////

static int	validate_map(t_line *map)
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

static int	is_map_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_input(line[i]))
			return (0);
		i++;
	}
	return (1);
}
static int	parse_line(char *line, t_line *map, t_color_data *c_data, t_texture_data *t_data)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	if (!map->map_started)
	{
		if (is_texture_line(line))
			return (parse_texture(&line[i], t_data));
		if (is_color_line(line))
			return (parse_color(&line[i], c_data));
		if (is_map_line(line))
		{
			map->map_started = 1;
			return(parse_map_line(&line[i], map));
		}
		return (print_error("Error: invalid line before map.\n"), EXIT_FAILURE);
	}
	if (!is_map_line(line))
		return (print_error("Error: invalid content after map.\n"), EXIT_FAILURE);
	return (parse_map_line(&line[i], map));
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
		if (parse_line(line, map, c_data, t_data) != EXIT_SUCCESS)
		{
			free(line);
			break ;
		}
		free(line);
	}
	get_next_line(-1);
	close(fd);
	if (!map->map_started)
		return (print_error("ERROR: No map found.\n"), EXIT_FAILURE);
	if (validate_map(map) != EXIT_SUCCESS)
		return (free(map->first_map_line), free(map->last_map_line),
			EXIT_FAILURE);
	free(map->first_map_line);
	free(map->last_map_line);
	return (EXIT_SUCCESS);
}
