/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimatl_upper.c                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:54:18 by abita             #+#    #+#             */
/*   Updated: 2025/05/13 14:21:44 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal_upper(unsigned int nb)
{
	char	*base;
	char	*buffer;
	int		i;
	int		length;

	length = 0;
	base = "0123456789ABCDEF";
	buffer = (char *)ft_calloc(17, sizeof(char));
	if (!buffer)
		return (-1);
	if (nb == 0)
	{
		free(buffer);
		return (ft_putchar('0'));
	}
	i = 0;
	while (nb > 0)
	{
		buffer[i++] = base[nb % 16];
		nb /= 16;
	}
	while (--i >= 0)
		length += ft_putchar(buffer[i]);
	free(buffer);
	return (length);
}
