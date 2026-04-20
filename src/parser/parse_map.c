/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:41:07 by abita             #+#    #+#             */
/*   Updated: 2026/04/18 20:40:22 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

/*
	1. The top and bottom row should be only 1's
	2. The first and last position in a row should be 1.
	3. A zero should be surrounded by: 1, 0, N, S, W, E
*/

int grid_validation(char **grid, int height, t_line *map)
{
    int x;
    int y;

	map->player_count = 0;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (grid[y][x])
        {
			if (is_player(grid[y][x]))
			{
				map->player.x = x;
				map->player.y = y;
				map->player_count++;
				if (map->player_count != 1)
					return (printf("ERROR: more than one player\n"), EXIT_FAILURE);
			}
            if (grid[y][x] == '0' || is_player(grid[y][x]))
            {
				if (y == 0 || x == 0 || y == height -1 || 
					x == (int)ft_strlen(grid[y]) - 1)
					{
						printf("ERROR: map is open at the borders\n");
						return (EXIT_FAILURE);
					}
				if (x >= (int)ft_strlen(grid[y - 1]) || x >= (int)ft_strlen(grid[y + 1]))
				{
					printf("ERROR: map is opened(ragged rows)\n");
					return (EXIT_FAILURE);
				}
                if (!is_valid(grid[y][x - 1]) || !is_valid(grid[y][x + 1]) || 
					!is_valid(grid[y - 1][x]) || !is_valid(grid[y + 1][x]))
					{
						printf("ERROR: map is not closed\n");
						return (EXIT_FAILURE);
					}
			}
            x++;
        }
        y++;
    }
	if (map->player_count != 1)
		return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int map_parsing(char *line, t_line *map)
{
	int i;
	char  *clean_line;

	i = 0;
	if (line[i] == '\0')
		return (EXIT_FAILURE);
	clean_line = ft_strtrim(&line[i], "\n");
	if (!clean_line)
		return (ERROR_MALLOC);
	map->grid = creating_2d_map(map->grid, clean_line);
	free(clean_line);
	if (!map->grid)
		return (EXIT_FAILURE);
	map->height++;
	return (EXIT_SUCCESS);
}
