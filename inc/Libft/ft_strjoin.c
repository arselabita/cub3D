/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:43:50 by abita             #+#    #+#             */
/*   Updated: 2025/04/29 15:43:54 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strcpy(new_str + s1_len, s2);
	return (new_str);
}
/*
int	main()
{
	char	str1[] = "arsela";
	char	str2[] = "bita";
	char	*new_str;

	new_str = ft_strjoin(str1, str2); 
	if (new_str != NULL)
	{
		printf("the 1st string: %s\n", str1);
		printf("the 2nd string: %s\n", str2);
		printf("the concatenated string: %s\n", new_str);
		free(new_str);
	}
	else
		printf("The memory allocation failed.");
	return (0);
}*/
