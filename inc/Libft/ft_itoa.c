/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:03:57 by abita             #+#    #+#             */
/*   Updated: 2025/05/05 19:26:29 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static void	ft_rev(char *tab, int size)
{
	int	i;
	int	end;
	int	temp;

	end = size - 1;
	i = 0;
	while (i < end)
	{
		temp = tab[i];
		tab[i] = tab[end];
		tab[end] = temp;
		i++;
		end--;
	}
}

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*var(int *i, int *minus, long int *nb, int n)
{
	char	*converted;

	*i = 0;
	*minus = 0;
	*nb = (long int)n;
	converted = (char *)ft_calloc((ft_numlen(n) + 1), sizeof(char));
	return (converted);
}

static int	handle_zero_and_negative(long int *nb, char *converted, int *minus)
{
	if (*nb == 0)
	{
		converted[0] = '0';
		return (1);
	}
	if (*nb < 0)
	{
		*minus = 1;
		*nb = -(*nb);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int			i;
	int			minus;
	long int	nb;
	char		*converted;

	converted = var(&i, &minus, &nb, n);
	if (!converted)
		return (NULL);
	if (handle_zero_and_negative(&nb, converted, &minus))
		return (converted);
	while (nb > 0)
	{
		converted[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (minus)
		converted[i++] = '-';
	ft_rev(converted, i);
	return (converted);
}
/*
int	main()
{
	int	num = -2147483648;
	char *value = ft_itoa(num);

	if (value)
	{
		printf("The number: %d\n", num);
		printf("Converted to string: %s\n", value);
		free(value);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}*/
