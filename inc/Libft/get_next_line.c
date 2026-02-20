/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:56:33 by abita             #+#    #+#             */
/*   Updated: 2026/02/20 20:17:23 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*line_to_return(char *leftovers)
{
	char	*print_line;
	size_t	i;
	size_t	j;
	size_t	remaining;

	i = 0;
	if (!leftovers)
		return (NULL);
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	if (leftovers[i] == '\n')
		i++;
	remaining = ft_strlen(leftovers) - i;
	print_line = (char *)ft_calloc(remaining + 1, sizeof(char));
	if (!print_line)
		return (free(leftovers), NULL);
	j = 0;
	while (leftovers[i])
		print_line[j++] = leftovers[i++];
	print_line[j] = '\0';
	free (leftovers);
	return (print_line);
}

static char	*copy_next_line(char *leftovers)
{
	size_t	i;
	char	*copied_line;

	i = 0;
	if (!leftovers)
		return (NULL);
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	copied_line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!copied_line)
		return (NULL);
	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
	{
		copied_line[i] = leftovers[i];
		i++;
	}
	if (leftovers[i] == '\n')
		copied_line[i++] = '\n';
	copied_line[i] = '\0';
	return (copied_line);
}

char	*helper_for_gnl(char *leftovers, int fd, char *buffer)
{
	ssize_t		bytes_to_read;
	char		*temp;

	bytes_to_read = 1;
	while (bytes_to_read > 0)
	{
		if (leftovers != NULL)
		{
			if (ft_strchr(leftovers, '\n') != NULL)
				break ;
		}
		bytes_to_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_to_read == -1)
			return (free(buffer), free (leftovers), NULL);
		buffer[bytes_to_read] = '\0';
		if (leftovers == NULL)
			temp = ft_strdup(buffer);
		else
			temp = ft_strjoin (leftovers, buffer);
		free(leftovers);
		leftovers = temp;
		if (leftovers == NULL)
			break ;
	}
	return (free(buffer), leftovers);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	static char	*leftovers;

	if (fd == -1)
		return (free(leftovers), leftovers = NULL, NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free (leftovers), leftovers = NULL, NULL);
	leftovers = helper_for_gnl(leftovers, fd, buffer);
	if (!leftovers || leftovers[0] == '\0')
		return (free(leftovers), leftovers = NULL, NULL);
	next_line = copy_next_line(leftovers);
	if (next_line == NULL)
		return (free(leftovers), leftovers = NULL, NULL);
	leftovers = line_to_return(leftovers);
	if (leftovers == NULL)
		return (free(next_line), NULL);
	return (next_line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
//      int     file_descriptor;
//      char    *next_line;
//      int     i;

//      i = 0;
//      file_descriptor = open("testfile", O_RDONLY);
//      if (file_descriptor == -1)
//      {
//          printf("Error opening the file");
//          return (1);
//      }
//     //  while (1)
//     //  {
//     //      next_line = get_next_line(file_descriptor);
//     //      if (next_line == NULL)
//     //          break ;
//     //      i++;
//     //      printf("[%d]: '%s'\n", i, next_line);
//     //      free (next_line);
//     //      next_line = NULL;
//     //  }

// 	 next_line = get_next_line(file_descriptor);
// 	 printf("[%d]: '%s'\n", i, next_line);
// 	 free (next_line);
// 	 next_line = NULL;
// 	 	 next_line = get_next_line(file_descriptor);
// 	 printf("[%d]: '%s'\n", i, next_line);
// 	 free (next_line);
// 	 next_line = NULL;

//      close(file_descriptor); // Close the file
//      return (0);
// }
