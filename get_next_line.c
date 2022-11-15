/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:34:50 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/15 23:23:18 by waraissi         ###   ########.fr       */
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
	line = ft_substr(backup,0,get_index(backup));
	backup = ft_substr(backup,get_index(backup) + 1,ft_strlen(backup)-get_index(backup));
	return (line);
}
// int main()
// {
//     int fd;
// 	char *x;

//     fd = open("txt.txt",O_RDONLY);
// 	x = get_next_line(fd);
//     printf("%s",x);
	
// }
