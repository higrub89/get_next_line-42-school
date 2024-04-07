/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:23:52 by rhiguita          #+#    #+#             */
/*   Updated: 2024/04/07 21:23:59 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif
#if BUFFER_SIZE > 125000 || BUFFER_SIZE < 1
#undef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif

char *get_next_line(int fd);
size_t ft_strget(char *line);
char *read_line(char *line, int *length);
char *ft_newline(char *line, char *stash, int *locate, int fd);
void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *s);
char *ft_strjoin_get(char *s1, char *s2, int *locate);
void ft_strlcpy_get(char *dst, const char *src, size_t dstsize);
void *ft_memcpy(void *dst, const void *src, size_t n);
int main();

#endif
