/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:54:05 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 13:56:00 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(void)
{
	t_data data;
	t_line line;

	printf("entering\n");				  // DEBUG
	if (open_file(&line) != EXIT_SUCCESS)
		return (ERROR_OPENING_FILE);
	printf("file reading finished\n"); 	  // DEBUG	
	printf("about to init the window\n"); // DEBUG
	init_window_and_display(&data);
	printf("init the window\n"); 		  // DEBUG
	mlx_loop_helper(&data);
	return (EXIT_SUCCESS);
}
