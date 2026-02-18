/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:56:47 by abita             #+#    #+#             */
/*   Updated: 2026/02/18 13:54:50 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int get_texture_type(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (NO);
	if (line[i] == 'S' && line[i + 1] == 'O')
		return (SO);
	if (line[i] == 'W' && line[i + 1] == 'E')
		return (WE);
	if (line[i] == 'E' && line[i + 1] == 'A')
		return (EA);
	return (ERROR);
}

char *get_path(char *line)
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
	return (path);
}

int	parse_texture(char *line, t_line *map)
{
	int i;
	int id;
	char *path;

	if (!line)
		return (0);
	// texture type if it is NO, SO, WE, EA
	id = get_id_type(line);
	printf("the texture type: %i\n", id);
	// check if it is a path
	path = get_path(line);
	printf("the path is: %s\n", path);
	if (id == NO && open(path))
	return (EXIT_SUCCESS);
}