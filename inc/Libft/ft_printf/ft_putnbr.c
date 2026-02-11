/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:54:40 by abita             #+#    #+#             */
/*   Updated: 2025/05/13 14:25:26 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long int	length;
	long int	n;

	length = 0;
	n = nb;
	if (n < 0)
	{
		length += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		length += ft_putnbr(n / 10);
	length += ft_putchar((n % 10) + '0');
	return (length);
}
