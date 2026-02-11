/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:04:40 by abita             #+#    #+#             */
/*   Updated: 2025/04/30 17:04:42 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	funct(unsigned int i, char ch)
{
	if ((i % 2 == 0) && (ch >= 'a' && ch <= 'z'))
		return (ch - 32);
	else if ((i % 2 != 0) && (ch >= 'A' && ch <= 'Z'))
		return (ch + 32);
	else
		return (ch);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	main()
{
	char	str[] = "Returns NULL if the allocation fails.";
	char	*value;

	value = ft_strmapi(str, funct);
	if (value != NULL)
	{
		printf("The input: %s\n", str);
		printf("The output: %s\n", value);
		free(value);
	}
	else
	{
		printf("Memory allocation failed!");
		free(value);
	}
	return (0);
}
