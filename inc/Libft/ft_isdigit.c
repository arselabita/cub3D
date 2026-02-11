/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:51:53 by abita             #+#    #+#             */
/*   Updated: 2025/04/23 09:51:57 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main ()
{
	printf("%d\n", ft_isdigit(0));
	printf("%d\n", ft_isdigit('2'));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit(' '));
	printf("%d\n", ft_isdigit(5));
	printf("%d\n", ft_isdigit('$'));
	return (0);
}*/
