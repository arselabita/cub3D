/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:07:43 by abita             #+#    #+#             */
/*   Updated: 2025/04/27 12:07:48 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		ch;
	const unsigned char	*str;

	ch = (unsigned char) c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	int	index;
	char	str[] = "abita";
	char *value;

	printf("The input: %s\n", str);
	value = ft_memchr(str, 't', ft_strlen(str));

	if (value)
	{
		printf("The char found: %s\n", value);
		index = (int)(value - str);
		printf("The index: %d\n", index);
	}
	else
		printf("The char is not found.\n");
	return (0);
}*/