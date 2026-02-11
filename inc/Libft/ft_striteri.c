/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:54:57 by abita             #+#    #+#             */
/*   Updated: 2025/05/01 15:54:58 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static void	funct(unsigned int i, char *ch)
{
	if ((i % 2 == 0) && (ch[i] >= 'a' && *ch <= 'z'))
		*ch -= 32;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
int	main()
{
	char	str[] = "Returns NULL if the allocation fails.";

	printf("The input: %s\n", str);
	ft_striteri(str, funct);
	printf("The output: %s\n", str);
	return (0);
}*/
