/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:41:20 by abita             #+#    #+#             */
/*   Updated: 2026/02/16 19:42:55 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initialize_line(t_line *line)
{
	line->first_map_line = NULL;
	line->last_map_line = NULL;
	line->is_first_line = 1;
	line->error = 0;
	line->player_count = 0;
}