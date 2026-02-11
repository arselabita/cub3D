/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:05:36 by abita             #+#    #+#             */
/*   Updated: 2025/04/23 17:05:39 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int	main()
{
	char	buffer[] = "Arsela!";
	int	i;

	printf("Before: %s\n", buffer);
	i = 0;
	while (i < 9)
	{
		printf("buffer[%d] = %c (%d)\n", i, buffer[i], buffer[i]);
		i++;
	}
	printf("\n");

	ft_bzero(buffer, 3);
	printf("After:\n");
	i = 0;
	while (i < 9)
	{
		printf("buffer[%d] = %c (%d)\n", i, buffer[i], buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
