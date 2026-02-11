/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:54:05 by abita             #+#    #+#             */
/*   Updated: 2026/02/11 21:09:43 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int is_valid_row(char *line)
{
	int i;
	int len;

	if (!line && line[0] == '\0')
		return (0);
	i = 0;
	len = 0;
	while (line[i] && line[i] != '\n')
		i++;
	len = i;
	if (line[0] != '1')
		return (0);
	if (line[len - 1] != '1')
		return (0);
	return (1);
}

int is_all_ones(char *last_map_line)
{
	int i;

	i = 0;
	while(last_map_line[i])
	{
		if (last_map_line[i] != '1' && !ft_isspace(last_map_line[i]))
			return (0);
		i++;
	}
	return (1);
}

int open_file(void)
{
	int			fd;
	char    	*next_line;
	char		*first_map_line;
	char		*last_map_line;
	int			is_first_line;

	fd = open("map.cub", O_RDONLY);
	if (fd == -1)
		return (print_error("Error: opening the file\n"), ERROR_FD);
	
	printf("opened the file\n");
	
	first_map_line = NULL;
	last_map_line = NULL;
	is_first_line = 1;
	
	while ((next_line = get_next_line(fd)) != NULL)
	{
		int i = 0;
		while(ft_isspace(next_line[i]))
			i++;
		////////////////
		// so, literally, what i do is that i created these 2 variables first and last row,
		// to keep track in case these rows are other than 1s. They should always be 1 nontheless
		// so what i do, i check for each char, and if the first_map_line is empty, 
		// then add only the first line
		// in case we have:
		// 		00000000
		// 		00000000
		// 		11111111
		// here our first_map_line will be: 00000000
		// where as the last_map_line will just be overwritten for each iteration until it reaches the end
		// and as a result our last_map_line will be: 11111111
		////////////////
		if (next_line[i] != '\0')
		{
			if (is_first_line)
			{
				first_map_line = ft_strdup(&next_line[i]);
				is_first_line = 0;
			}
			free(last_map_line);
			last_map_line = ft_strdup(&next_line[i]);
			if (!is_valid_row(&next_line[i]))
				return (print_error("ERROR: Row must start and end with 1\n"),
					free(first_map_line), free(last_map_line), free(next_line), 
					close(fd), EXIT_FAILURE);	
		}
		printf("%s\n", next_line);
		free(next_line);
	}
	close (fd);
	////////////////
	// here i validate the first and last rows to check if it contains 1 or also spaces,
	// if it contains smth else than it frees and displays error, that the map is not valid
	////////////////
	if (first_map_line && !is_all_ones(first_map_line))
		return (print_error("ERROR: First row must be all 1\n"),
			free(first_map_line), free(last_map_line), EXIT_FAILURE);
	if (last_map_line && !is_all_ones(last_map_line))
		return (print_error("ERROR: Last row must be all 1\n"),
			free(first_map_line), free(last_map_line), EXIT_FAILURE);
	free(first_map_line);
	free(last_map_line);
	printf("Map validation passed\n");
	return (EXIT_SUCCESS);
}

int main()
{	
	t_data		data;

	printf("entering\n");
	
	if (open_file() != EXIT_SUCCESS)
		return (print_error("ERROR: opening the file\n"), ERROR_OPENING_FILE);
	
	printf("file reading finished\n");
	printf("about to init the window\n");
	
	init_window_and_display(&data);

	printf("init the window\n");
	
	mlx_loop_helper(&data);
	return (EXIT_SUCCESS);
}