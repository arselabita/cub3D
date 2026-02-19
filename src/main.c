/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:54:05 by abita             #+#    #+#             */
/*   Updated: 2026/02/19 15:41:15 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	input_validity(t_line *line, t_data *data, int argc, char **argv)
{
	char	*path;
	char	*dot;
	t_color_data c_data;
	t_texture_data t_data;

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
	path = argv[1];
	dot = ft_strrchr(path, '.');
	if (!dot || ft_strcmp(dot, ".cub") != 0)
	{
		print_error("ERROR: map must have '.cub' extention.\n");
		return (EXIT_FAILURE);
	}
	if (parser(path, line, &c_data, &t_data) != EXIT_SUCCESS)
		return (ERROR_OPENING_FILE);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_line	line;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&line, sizeof(t_line));
	if (input_validity(&line, &data, argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	init_window_and_display(&data);
	mlx_loop_helper(&data);
	return (EXIT_SUCCESS);
}
