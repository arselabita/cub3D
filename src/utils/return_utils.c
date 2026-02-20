/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:29:49 by abita             #+#    #+#             */
/*   Updated: 2026/02/17 14:01:08 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_error(const char *msg)
{
	write(STDERR_FILENO, RED, 5);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, RED, 5);
}
