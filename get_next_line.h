/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:35:47 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/16 19:26:16 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

# include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char  *s1, char  *s2);
int     get_index(char	*str);
char	*before_newline(char *str);
char	*after_newline(char *str);
char    *get_next_line(int fd);

#endif