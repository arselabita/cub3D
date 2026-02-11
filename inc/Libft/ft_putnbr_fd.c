/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:58:44 by abita             #+#    #+#             */
/*   Updated: 2025/05/01 15:58:45 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		print;
	long int	nb;

	nb = (long int) n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	print = (nb % 10) + '0';
	write(fd, &print, 1);
}
int	main()
{
	int	fd;

	fd = open("num.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	printf("fd: %d\n", fd);
	ft_putnbr_fd(-2147483647, fd);
	close (fd);
	return (0);
}
