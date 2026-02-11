/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:34:09 by abita             #+#    #+#             */
/*   Updated: 2025/04/24 11:34:11 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	end;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	end = size - 1;
	while (src[i] && i < end)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*int	main()
{
	char	src[20] = "arsela";
	char	dest[20];
	size_t	result = ft_strlcpy(dest, src, sizeof(dest));

	printf("the result: %s\n", dest);
	printf("length: %zu\n", result);
	return (0);	
}*/
