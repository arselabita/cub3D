/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:56:47 by abita             #+#    #+#             */
/*   Updated: 2026/02/19 15:39:30 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_id_type(char *line)
{
	int	i;

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
	return (-1);
}

static char	*get_path(char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i += 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	path = (char *)malloc((ft_strlen(line + i)) + 1 * sizeof(char));
	if (!path)
		return (NULL);
	ft_strlcpy(path, line + i, ft_strlen(line+i));
	return (path);
}

int	parse_texture(char *line, t_texture_data *t_data)
{
	int id;
	int fd;
	char *path;

	// texture type if it is NO, SO, WE, EA
	id = get_id_type(line);
	// printf("the texture type: %i\n", id);
	// check if it is a path
	path = get_path(line);
	// printf("the path is: %s\n", path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (id == NO)
		t_data->no = fd;
	if (id == SO)
		t_data->so = fd;
	if (id == WE)
		t_data->we = fd;
	if (id == EA)
		t_data->ea = fd;
	return (EXIT_SUCCESS);
}