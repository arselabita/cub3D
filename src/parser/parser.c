/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:02:56 by abita             #+#    #+#             */
/*   Updated: 2026/02/17 15:37:44 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	parse_line(char *line, t_line *map)
{
	char	*p;
	int		i;

	p = skip_whitespace(line);
	i = 0;
	if (p[i] == '\0' || p[i] == '\n')
		return (EXIT_SUCCESS);
	if (!map->map_started)
	{
		if (is_texture_line(p))
			return (parse_textures(&line[i], map));
		if (is_color_line(p))
			return (parse_color(&line[i], map));
		map->map_started = 1;
	}
	parse_map_line(&line[i], map);
	return (EXIT_SUCCESS);
}

int	parser(char *path, t_line *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error("Error: opening the file\n"), ERROR_FD);
	init_line(map);
	while ((line = get_next_line(fd)))
	{
		if (parse_line(line, map) != EXIT_SUCCESS)
		{
			free(line);
			break ;
		}
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
