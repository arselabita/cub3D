/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:54:05 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 19:03:22 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	input_validity(t_line	*line, t_data *data, int argc, char **argv)
{
	if (argc < 2)
	{
		write (2, "WARNING: [pass a map file: '.cub'].\n", 37);
		ft_exit_error(data);
	}
	if (argc > 2)
	{
		write(2, "WARNING: [too many arguments].\n", 32);
		ft_exit_error(data);
	}
	char *path;
	char *dot_found;
	// int compare;

	path = argv[1];
	printf("path: %s\n", path);
	dot_found = ft_strrchr(path, '.');
	if (!dot_found)
		return (EXIT_FAILURE);
	printf("dot_found: %s\n", dot_found);
	// printf("compare: %i\n", compare);
	// compare = ft_strcmp(dot_found, ".cub");
	if (ft_strcmp(dot_found, ".cub") == 0)
	{ 
		if (open_file(path, line) != EXIT_SUCCESS)
			return (ERROR_OPENING_FILE);
	}		
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_line	line;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&line, sizeof(t_line));

	printf("entering\n"); // DEBUG
	input_validity(&line, &data, argc, argv);
	printf("file reading finished\n");    // DEBUG
	printf("about to init the window\n"); // DEBUG
	init_window_and_display(&data);
	printf("init the window\n"); // DEBUG
	mlx_loop_helper(&data);
	return (EXIT_SUCCESS);
}
