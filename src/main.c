/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milija-h <milija-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:54:05 by abita             #+#    #+#             */
/*   Updated: 2026/04/19 17:54:34 by milija-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	input_validity(t_line *line, t_data *data, int argc, char **argv)
{
	char			*dot;
	char			*slash;
	t_color_data	c_data;
	t_texture_data	t_data;

	if (argc < 2)
	{
		print_error("WARNING: pass a map file: '.cub'.\n");
		ft_exit_error(data);
	}
	if (argc > 2)
	{
		print_error("WARNING: too many arguments.\n");
		ft_exit_error(data);
	}
	slash = ft_strrchr(argv[1], '/');
	if (slash && slash[1] == '.')
	{
		printf("error: this is a hidden path\n");
		return (EXIT_FAILURE);
	}
	dot = ft_strrchr(argv[1], '.');
	if (!dot || ft_strcmp(dot, ".cub") != 0)
	{
		print_error("ERROR: map must have '.cub' extention.\n");
		return (EXIT_FAILURE);
	}
	if (parser(argv[1], line, &c_data, &t_data) != EXIT_SUCCESS)
		return (ERROR_OPENING_FILE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_line		line;
	t_player	player;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&line, sizeof(t_line));
	if (input_validity(&line, &data, argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	init_window_and_display(&data);
	init_player(&player, &line);
	data.player = &player;
	data.line = &line;
	//render_grid(&data, &player, line.grid);
	mlx_loop_helper(&data);
	//free_split(line.grid);
	return (EXIT_SUCCESS);
}
