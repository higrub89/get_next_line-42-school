/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:47:33 by rhiguita          #+#    #+#             */
/*   Updated: 2024/03/24 04:20:11 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s != (unsigned char)c)
        if (!*s++)
            return (0);
    return ((char *)s);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t  i;
    char    *d;
    char    *s;

    d = (char *)dest;
    s = (char *)src;
    i = 0;
    if (!dest && !src)
    {
        return (NULL);
    }
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  s1_len;
    size_t  s2_len;
    size_t  i;
    char    *result;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    i = s1_len + s2_len;
    result = (char *)malloc(sizeof(char) * (i + 1));
    if (result == NULL)
    {
        return (NULL);
    }
    ft_memcpy(result, s1, s1_len);
    ft_memcpy(result + s1_len, s2, s2_len);
    result[i] = '\0';
    return (result);
}

char	*ft_strjoin2(char *ch, char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		ch[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		ch[i + j] = s2 [j];
		j++;
	}
	ch[i + j] = '\0';
	return (ch);
}
