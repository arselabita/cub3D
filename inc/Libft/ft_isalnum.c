/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:36:57 by abita             #+#    #+#             */
/*   Updated: 2025/04/23 10:36:59 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'z') || \
		(c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int main()
{
    printf("%d\n", ft_isalnum('A'));
    printf("%d\n", ft_isalnum('z'));
    printf("%d\n", ft_isalnum('5'));
    printf("%d\n", ft_isalnum(' '));
    printf("%d\n", ft_isalnum('&'));
    return (0);
}*/
