/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:55:43 by abita             #+#    #+#             */
/*   Updated: 2025/04/29 10:55:44 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length_of_s;
	char	*sub;

	if (!s)
		return (NULL);
	length_of_s = ft_strlen(s);
	if (start > length_of_s)
		len = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

int	main()
{
	char	str[] = "The substring starts at index ’start’.";
	char	*substr;
	
	substr = ft_substr(str, 5, 9);
	if (substr != NULL)
	{
		printf("The string: %s\n", str);
		printf("The sub-string: %s\n", substr);
		free(substr);
	}
	else
		printf("Failed to allocate memory.\n");
	return (0);
}
