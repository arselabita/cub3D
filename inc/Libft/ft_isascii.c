/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:45:20 by abita             #+#    #+#             */
/*   Updated: 2025/04/23 10:45:22 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main()
{
    printf("%d\n", ft_isascii(65));
    printf("%d\n", ft_isascii(127));
    printf("%d\n", ft_isascii(128));
    printf("%d\n", ft_isascii(-65));
    return (0);
}*/
