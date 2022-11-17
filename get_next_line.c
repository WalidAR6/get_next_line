/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:34:50 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/17 13:17:19 by waraissi         ###   ########.fr       */
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
	while (str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
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
		return (free(str),NULL);
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
	if (j ==  ft_strlen(str))
		return (free(str),NULL);
	s = malloc(ft_strlen(str) - j + 1);
	if (!s)
		return (NULL);
	while (str[j])
		s[i++] = str[j++];
	s[i] = '\0';
	return (free(str), str=NULL, s);
}

int	is_newline(char *str)
{
	int i; 
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if(str[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;
	char 		*tmp;
	ssize_t		i;

	i = 1;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buffer)
		return (NULL);
	while (i && is_newline(backup) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if(i == -1 || (i ==0 && backup == NULL))
			return (free(backup),free(buffer),NULL);
		buffer[i] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	line = before_newline(backup);
	backup = after_newline(backup);
	return (free(buffer),line);
}

// int main()
// {
//     int fd;

//     fd = open("txt.txt",O_RDONLY);
// 	char *s =get_next_line(fd);
// 	while (s)
// 	{
// 		printf("%s", s);
// 		free(s);
// 		s=get_next_line(fd);
// 	}
// 	printf("%s", s);
// 		free(s);
// 	// printf("line ==> %s", get_next_line(fd));
// 	//system ("leaks a.out");
	
// 	close(fd);
// }
