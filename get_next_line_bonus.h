/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:27:53 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/23 17:09:21 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include<fcntl.h>

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t n);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		is_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		get_index(char	*str);
char	*before_newline(char *str);
char	*after_newline(char *str);
char	*get_next_line(int fd);

#endif