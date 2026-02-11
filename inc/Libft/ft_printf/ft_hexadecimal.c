/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:54:08 by abita             #+#    #+#             */
/*   Updated: 2025/05/13 14:19:21 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int nb)
{
	char	*base;
	char	*buffer;
	int		i;
	int		length;

	length = 0;
	base = "0123456789abcdef";
	buffer = (char *)ft_calloc(17, sizeof(char));
	if (!buffer)
		return (-1);
	if (nb == 0)
	{
		free (buffer);
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
	free (buffer);
	return (length);
}
