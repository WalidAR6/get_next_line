/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:34:50 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/16 20:06:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<fcntl.h>

int get_index(char	*str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i] && *(str + i) != '\n')
		i++;
	
	return(i);
}

char	*before_newline(char *str)
{
	int	i;
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
	if(str[i] == '\n')
		p[i++] = '\n';
	p[i] = 0;
	return (p);
}

char	*after_newline(char *str)
{
	int	i;
	size_t	j;
	char *s;

	i = 0;
	if (!str[i])
		return (NULL);
	j = get_index(str);
	// if(str[j] == '\n')
	// 	printf("ok");
	if (j ==  ft_strlen(str))
		return (free(str),NULL);
	s = malloc(ft_strlen(str) - j + 1);
	if (!s)
		return (NULL);
	while (str[j])
		s[i++] = str[j++];
	s[i] = '\0';
	return (free(str),str=NULL,s);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;
	size_t		i;

	i = 1;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if (!backup)
        backup = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if(!buffer)
			return NULL;
	while (i && !ft_strchr(backup, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if(i < 0)
			return (free(backup),backup = NULL,free(buffer),NULL);
		*(buffer + i) = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	line = before_newline(backup);
	free(buffer);
	backup = after_newline(backup);
	return (line);
}

// int main()
// {
//     int fd;

//     fd = open("txt.txt",O_RDONLY);
// 	printf("line ==> %s", get_next_line(fd));
// 	printf("line ==> %s", get_next_line(fd));
// 	printf("line ==> %s", get_next_line(fd));
// 	printf("line ==> %s", get_next_line(fd));
// 	printf("line ==> %s", get_next_line(fd));
// 	printf("line ==> %s", get_next_line(fd));
// 	printf("line ==> %s", get_next_line(fd));
// 	printf("line ==> %s", get_next_line(fd));
// 	close(fd);
// char *str ;
// printf("%d",get_index("hvdjhvsudsuh"));
// 	str = ft_strdup("aaaaaaa\nbbbbbbbbb");
// 	printf("%s",after_newline(str));
// }
