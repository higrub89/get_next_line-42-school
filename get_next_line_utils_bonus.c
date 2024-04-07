/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:24:24 by rhiguita          #+#    #+#             */
/*   Updated: 2024/04/07 22:12:16 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void ft_bzero(void *s, size_t n)
{
  while (n--)
    *(char *)s++ = 0;
}

size_t ft_strlen(const char *s)
{
  size_t i;

  i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return (i);
}

char *ft_strjoin_get(char *s1, char *s2, int *locate)
{
  char *ptr;
  size_t s1_len;
  size_t s2_len;

  if (!s1 || !s2)
    return (NULL);
  s1_len = ft_strlen(s1);
  s2_len = ft_strlen(s2);
  ptr = (char *)malloc(s1_len + s2_len + 1);
  if (!ptr)
  {
    free(s1);
    return (NULL);
  }
  ft_memcpy(ptr, s1, s1_len);
  free(s1);
  ft_memcpy(ptr + s1_len, s2, s2_len + 1);
  if (s1_len + s2_len > 0 && *(ptr + s1_len + s2_len - 1) == '\n')
    *locate = 0;
  return (ptr);
}

void ft_strlcpy_get(char *dst, const char *src, size_t dstsize)
{
  size_t i;

  i = 0;
  if (dstsize > 0)
  {
    while (src[i] && i < dstsize - 1)
    {
      dst[i] = src[i];
      i++;
    }
    dst[i] = '\0';
  }
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
  unsigned char *d;
  unsigned char *s;

  if (!dst && !src)
    return (NULL);
  d = (unsigned char *)dst;
  s = (unsigned char *)src;
  while (n--)
    *d++ = *s++;
  return (dst);
}
