/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:47:33 by rhiguita          #+#    #+#             */
/*   Updated: 2024/03/28 22:35:32 by rhiguita         ###   ########.fr       */
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
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (unsigned char)c)
        return ((char *)s);
    else
        return (NULL);
}

char    *ft_strcpy(char *dest, const char *src)
{
    char    *d;

    d = dest;
    if (!src)
        return (NULL);
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (d);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    size_t  s1_len;
    size_t  s2_len;
    size_t  len;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    len = s1_len + s2_len;
    result = (char *)malloc((len + 1) * (sizeof(char)));
    if (result == NULL)
        return (NULL);
    ft_memcpy(result, s1, s1_len);
    ft_memcpy(result + s1_len, s2, s2_len);
    result[len] = '\0';
    return (result);
}

char    *ft_strdup(const char *s1)
{
    char    *p;
    size_t  len;

    len = ft_strlen(s1);
    p = (char *)malloc((len + 1) * (sizeof(char)));
    if (!p)
        return (NULL);
    return (ft_strcpy(p, src));
}
