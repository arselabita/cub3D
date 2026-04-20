/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:56:47 by abita             #+#    #+#             */
/*   Updated: 2026/04/18 20:37:09 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"



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
	ft_strlcpy(path, line + i, ft_strlen(line + i));
	return (path);
}

int	parse_texture(char *line, t_texture_data *t_data)
{
	int id;
	char *path;
	char *dot;
	char *slash;

	id = get_id_type(line);
	path = get_path(line);
	if (!path)
		return (-1);
	slash = ft_strrchr(path, '/');
	if (slash && slash[1] == '.')
	{
		printf("error: this is a hidden path\n");
		return (EXIT_FAILURE);
	}
	dot = ft_strrchr(path, '.');
	if (!dot || ft_strcmp(dot, ".xpm") != 0)
		return (printf("error: .xpm exe\n"), EXIT_FAILURE);
	if (id == -1)
		return (-1);
	if (id == NO)
		t_data->no = path;
	if (id == SO)
		t_data->so = path;
	if (id == WE)
		t_data->we = path;
	if (id == EA)
		t_data->ea = path;
	free(path);
	return (EXIT_SUCCESS);
}
