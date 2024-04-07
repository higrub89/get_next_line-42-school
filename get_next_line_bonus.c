/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:46:07 by rhiguita          #+#    #+#             */
/*   Updated: 2024/04/07 21:10:32 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t ft_strget(char *line)
{
	size_t i;

	i = 0;
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char *read_line(char *line, int *length)
{
	char *stash;
	size_t len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	len++;
	stash = (char *)malloc((len + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	ft_memcpy(stash, line, len);
	stash[len] = '\0';
	if (len > 0 && stash[len - 1] == '\n')
		*length = len - 1;
	return (stash);
}
char *ft_newline(char *line, char *stash, int *locate, int fd)
{
	ssize_t read_bytes;
	size_t line_len;
	char buffer[BUFFER_SIZE + 1];

	while (*locate == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(line);
			ft_bzero(stash, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_len = ft_strget(buffer);
		ft_strlcpy_get(stash, &buffer[line_len], (BUFFER_SIZE + 1));
		buffer[line_len] = '\0';
		line = ft_strjoin_get(line, buffer, locate);
		if (read_bytes == 0)
		{
			ft_bzero(stash, BUFFER_SIZE + 1);
			break;
		}
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	int bytes_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_line = -1;
	line = read_line(buffer, &bytes_line);
	if (!line)
		return (NULL);
	ft_strlcpy_get(buffer, &buffer[bytes_line + 1], BUFFER_SIZE + 1);
	line = ft_newline(line, buffer, &bytes_line, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
