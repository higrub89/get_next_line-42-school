/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:37:15 by rhiguita          #+#    #+#             */
/*   Updated: 2024/03/24 04:07:06 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
