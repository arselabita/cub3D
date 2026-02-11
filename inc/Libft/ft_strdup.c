/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:19:16 by abita             #+#    #+#             */
/*   Updated: 2025/05/01 15:19:18 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
int	main()
{
	const char	*str = "helloww";
	char	*duplicate;

	duplicate = ft_strdup(str);
	if (duplicate != NULL)
	{
		printf("the original string: %s\n", str);
		printf("the duplicated string: %s\n", duplicate);
		free(duplicate);
	}
	else
		printf("Memoryy allocation failed.\n");
	return (0);
}*/
