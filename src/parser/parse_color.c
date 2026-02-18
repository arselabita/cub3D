/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:00:00 by abita             #+#    #+#             */
/*   Updated: 2026/02/18 13:45:43 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int get_id_type(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'F')
		return (F);
	if (line[i] == 'C')
		return (C);
	return (ERROR);
}

void get_color_range(char *line)
{
	int i;
	char *path;

	i = 0;
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	i += 2;
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	path = (char *)malloc((ft_strlen(line + i)) + 1 * sizeof(char));
	if (!path)
		return(NULL);
	ft_strcpy(path, line + i);
	
}

int parse_color(char *line, t_line *map)
{
	int i;
	int id;
	char *color_range;

	if (!line)
		return (0);
	id = get_id_type(line);
	printf("the color type: %i\n", id);
	color_range = get_color_range(line);
	printf("color range: \n", color_range);
	return (EXIT_SUCCESS);
}