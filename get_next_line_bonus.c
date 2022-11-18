/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:24:50 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/18 15:26:27 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_index(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*before_newline(char *str)
{
	int		i;
	char	*p;

	i = 0;
	if (!str[i])
		return (NULL);
	p = malloc(sizeof(char) * get_index(str) + 1);
	if (!p)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		p[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		p[i++] = '\n';
	p[i] = 0;
	return (p);
}

char	*after_newline(char *str)
{
	int		i;
	size_t	j;
	char	*s;

	i = 0;
	j = get_index(str);
	if (j == ft_strlen(str))
		return (free(str), NULL);
	s = malloc(ft_strlen(str) - j + 1);
	if (!s)
		return (NULL);
	while (str[j])
		s[i++] = str[j++];
	s[i] = '\0';
	return (free(str), str = NULL, s);
}

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buffer;
	char		*line;
	ssize_t		i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (i && is_newline(backup[fd]) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(backup[fd]), free(buffer), backup[fd] = NULL, NULL);
		buffer[i] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buffer);
	}
	line = before_newline(backup[fd]);
	backup[fd] = after_newline(backup[fd]);
	return (free(buffer), line);
}
