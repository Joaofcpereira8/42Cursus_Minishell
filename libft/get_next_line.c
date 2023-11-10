/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:43:50 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:14:35 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Read a line from a file descriptor.
 *
 * @param fd File descriptor to read from.
 * @param buffer Temporary buffer to store read data.
 * @param stash Stash to store remaining data from the last read.
 *
 * @return Returns a line read from the file descriptor, or NULL if an
 *         error occurs.
 */
static char	*ft_get_line(int fd, char *buffer, char *stash)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (0);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

/**
 * Get the stash containing remaining data after a newline
 * character in the line.
 *
 * @param line Line to extract the stash from.
 *
 * @return Returns the stash, or NULL if no newline character is found.
 */
static char	*ft_get_stash(char *line)
{
	int		i;
	char	*stash;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = 0;
	}
	line[i + 1] = '\0';
	return (stash);
}

/**
 * Get the next line from a file descriptor.
 *
 * @param fd File descriptor to read from.
 *
 * @return Returns the next line read from the file descriptor,
 *         or NULL if an error occurs or the end of file is reached.
 */
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_get_line(fd, buffer, stash);
	free(buffer);
	if (!line)
	{
		free(stash);
		stash = 0;
		return (stash);
	}
	stash = ft_get_stash(line);
	return (line);
}
