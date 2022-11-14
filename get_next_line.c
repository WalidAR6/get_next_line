/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:34:50 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/14 21:52:30 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if ((*str == (char)c))
			return ((char *)str);	
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (dst == NULL || n == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *str)
{
	char	*p;

	p = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, str, ft_strlen(str) + 1);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j])
		p[i + j] = s2[j];
	p[i + j] = 0;
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s) - start;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	while (s[i] && i < len)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}

int get_index(char	*str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while (*str != '\n')
	{
		str++;
		i++;
	}
	return(i);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*backup;
	char		*line;
	size_t		i;

	i = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!backup)
        backup = ft_strdup("");
	while (buffer && i != 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if(i < 0)
			return (NULL);
		if (i == 0)
			return (backup);
		*(buffer + i) = '\0';	
		backup = ft_strjoin(backup, buffer);
	}
	printf("%s\n",backup);
	printf("--------------\n");
	while (backup && !ft_strchr(backup,'\n'))
	{
		if (!line)
			line = ft_strdup("");
		line = ft_substr(backup,0,get_index(backup));
	}
	printf("%s\n",line);
	printf("--------------\n");
	return (line);
}
int main()
{
    int fd;
	char *x;

    fd = open("txt.txt",O_RDONLY);
	x = get_next_line(fd);
    printf("%s",x);
}
