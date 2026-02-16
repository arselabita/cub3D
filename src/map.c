/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:55:41 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 19:03:19 by abita            ###   ########.fr       */
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
void	process_map_line(char *next_line, t_line *line)
{
	int	i;

	i = 0;
	while (ft_isspace(next_line[i]))
		i++;
	if (next_line[i] == '\0')
		return ;
	if (line->is_first_line)
	{
		line->first_map_line = ft_strdup(&next_line[i]);
		line->is_first_line = 0;
	}
	free(line->last_map_line);
	line->last_map_line = ft_strdup(&next_line[i]);
	if (!is_valid_row(&next_line[i]))
		line->error = 1;
}
////////////////
// here i validate the first and last rows to check if it 
// contains 1 or also spaces,
// if it contains smth else than it frees and displays error,
//	that the map is not valid
////////////////
int	validate_map_borders(t_line *line)
{
	if (!line->error)
	{
		if (line->first_map_line && !is_all_ones(line->first_map_line))
			line->error = 1;
		if (line->last_map_line && !is_all_ones(line->last_map_line))
			line->error = 1;
	}
	if (line->error)
	{
		print_error("ERROR: Invalid map\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	open_file(char *path, t_line *line)
{
	int		fd;
	char	*next_line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error("Error: opening the file\n"), ERROR_FD);
	printf("opened the file\n"); // DEBUG
	initialize_line(line);
	while ((next_line = get_next_line(fd)))
	{
		printf("%s\n", next_line);
		if (!is_valid_map_char(next_line))
		{
			line->error = 1;
			free(next_line);
			break ;
		}
		process_map_line(next_line, line);
		free(next_line);
		if (line->error)
			break ;
	}
	// this bcs inside gnl i use a static var
	// and it causes leaks when i pass invalid map
	get_next_line(-1);
	close(fd);
	if (validate_map_borders(line) != EXIT_SUCCESS)
		return (free(line->first_map_line), free(line->last_map_line),
			EXIT_FAILURE);
	printf("Map validation passed\n"); // DEBUG
	free(line->first_map_line);
	free(line->last_map_line);
	return (EXIT_SUCCESS);
}
