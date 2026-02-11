/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:54:48 by abita             #+#    #+#             */
/*   Updated: 2025/04/30 16:54:49 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main()
{
	char	ch;
	int	fd;

	ch = 'a';
	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	printf("fd: %d\n", fd);
	ft_putchar_fd(ch, fd);
	
	close (fd);
	return (0);
}*/
