/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:53:55 by abita             #+#    #+#             */
/*   Updated: 2025/05/13 20:25:27 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	function_p_helper(va_list args)
{
	int			length;
	void		*address;

	address = va_arg(args, void *);
	if (address == NULL)
		return (write(1, "(nil)", 5));
	length = 0;
	length += ft_putstr("0x");
	length += (ft_hexadecimal_pointer((uintptr_t)address));
	return (length);
}

static int	handle_s_helper(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	return (ft_putstr(str));
}

static int	format_specifiers(const char *format, int i, va_list args)
{
	if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i] == 's')
		return (handle_s_helper(args));
	else if (format[i] == 'p')
		return (function_p_helper(args));
	else if (format[i] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (format[i] == 'x')
		return (ft_hexadecimal(va_arg(args, unsigned int)));
	else if (format[i] == 'X')
		return (ft_hexadecimal_upper(va_arg(args, unsigned int)));
	else if (format[i] == '%')
		return (ft_putchar(format[i]));
	else
	{
		ft_putchar('%');
		ft_putchar(format[i]);
		return (2);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		i;

	i = 0;
	length = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] && i < INT_MAX - 2)
	{
		if (format[i] == '%' && format[i + 1])
			length += format_specifiers(format, ++i, args);
		else if (format[i] == '%' && !format[i + 1])
			return (va_end(args), -1);
		else
			length += ft_putchar(format[i]);
		i++;
	}
	return (va_end(args), length);
}
