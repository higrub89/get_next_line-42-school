/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:19:20 by rhiguita          #+#    #+#             */
/*   Updated: 2024/04/04 00:29:12 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//función toma un string y devuelve la longitud del string hasta el primer salto de línea (\n) o el final de la cadena (\0).
// Se utiliza para determinar la longitud de la línea que se está leyendo.
size_t	ft_strget(char *line)
{
	size_t	i;

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
//Esta función toma una cadena de caracteres y un puntero a un entero. 
//ee la cadena hasta el primer salto de línea o el final de la cadena, asigna memoria para una nueva cadena que contiene la línea leída, y actualiza el entero al que apunta el puntero para reflejar la longitud de la línea.
//Se utiliza para extraer una línea de una cadena de caracteres.
char	*read_line(char *line, int *length)
{
	char	*stash;
	size_t	len;

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

// Funcion que toma una línea, un búfer, un puntero a un entero que indica la ubicación en la línea, y un descriptor de archivo.
// Lee del descriptor de archivo en el búfer, procesa la línea en el búfer, y continúa leyendo y procesando hasta que se ha leído una línea completa o se ha alcanzado el final del archivo.
// Se utiliza para leer líneas de un descriptor de archivo.
char	*ft_newline(char *line, char *stash, int *locate, int fd)
{
	ssize_t	read_bytes;
	size_t	line_len;
	char	buffer[BUFFER_SIZE + 1];

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
			break ;
		}
	}
	return (line);
}


//Toma un descriptor de archivo y utiliza las otras funciones para leer líneas del descriptor de archivo una a la vez.
//Cada llamada a get_next_line devuelve la siguiente línea del archivo.
//Esta función es útil para procesar un archivo línea por línea, ya que solo mantiene una línea en memoria a la vez.
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_line;	

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
