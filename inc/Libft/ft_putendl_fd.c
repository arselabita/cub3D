/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:57:30 by abita             #+#    #+#             */
/*   Updated: 2025/05/01 15:57:31 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int	main()
{
	char	str[] = "arsela";
	int	fd;

	fd = open("test1.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	printf("fd: %d\n", fd);
	ft_putendl_fd(str, fd);

	close(fd);
	return (0);
}*/
