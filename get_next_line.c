/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:37:15 by rhiguita          #+#    #+#             */
/*   Updated: 2024/03/24 17:28:54 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
char *get_next_line(int fd)
{
	static char	*s;
	char 		*buffer;
	int			*bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!(ft_strchr(s, '\n')) && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_free(buffer, &s);
			return (NULL);
		}
		buffer[bytes] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	buffer = ft_trim(s);
	s = ft_newline(s);
	return (buffer);
}*/
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
	int	fd = open("file.txt", O_RDWR);
	char *s = "Ruben Dario";
	size_t i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, (int *)'\n', 1);
	close(fd);
	return (0);

}
