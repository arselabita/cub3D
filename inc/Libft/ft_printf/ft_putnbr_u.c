/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:54:49 by abita             #+#    #+#             */
/*   Updated: 2025/05/13 14:27:15 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	unsigned int	length;

	length = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb >= 10)
		length += ft_putnbr_u(nb / 10);
	length += ft_putchar((nb % 10) + '0');
	return (length);
}
