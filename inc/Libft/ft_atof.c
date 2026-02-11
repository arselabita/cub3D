/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:00:59 by abita             #+#    #+#             */
/*   Updated: 2025/08/07 19:01:04 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void parse_integer_part(const char *nptr, t_atof *a)
{
	while ((nptr[a->i] >= '\t' && nptr[a->i] <= '\r') || nptr[a->i] == ' ')
		a->i++;
	if (nptr[a->i] == '-' || nptr[a->i] == '+')
	{
		if (nptr[a->i] == '-')
			a->sign = -1;
		a->i++;
	}
	while (nptr[a->i] >= '0' && nptr[a->i] <= '9')
	{
		a->result = a->result * 10.0 + (nptr[a->i] - '0');
		a->i++;
	}
}
double	ft_atof(const char *nptr)
{
	t_atof a;

	a.sign = 1;
	a.result = 0.0;
	a.factor = 0.1;
	a.i = 0.0;
	parse_integer_part(nptr, &a);
	if (nptr[a.i] == '.')
	{
		a.i++;
		while (nptr[a.i] >= '0' && nptr[a.i] <= '9')
		{
			a.result += (nptr[a.i] - '0') * a.factor;
			a.factor *= 0.1;
			a.i++;
		}
	}
	return (a.result * a.sign);
}
