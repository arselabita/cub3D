/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:15:04 by abita             #+#    #+#             */
/*   Updated: 2025/04/29 17:15:07 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		length;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	length = end - start + 1;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

int main()
{
	char	str[] = "ter array must end with a NULL pointer";
	char	rem_chr[] = "ter";
	char	*trimed_str;

	trimed_str = ft_strtrim(str, rem_chr);
	if (trimed_str)
	{
		printf("the string: %s\n", str);
		printf("the char to remove: %s\n", rem_chr);
		printf("trimed string: %s\n", trimed_str);
		free(trimed_str);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}
