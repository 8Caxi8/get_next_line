/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:28:04 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/10 17:40:17 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

int	find_bline(char *buffer)
{
	int	len;

	len = 0;
	while (buffer[len] && len < BUFFER_SIZE + 1)
	{
		if (buffer[len] == '\n')
			break ;
	len++;
	}
	return (len);
}

char	*read_file(int fd, char *buffer)
{
	int	nbytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	nbytes = read(fd, buffer, BUFFER_SIZE);
	if (nbytes <= 0)
		return (NULL);
	return (buffer);
}
char	*add_text(char *line, char *buffer)
{
	char	*temp;
	
	temp = line;
	line = ft_strjoin(temp,  buffer);
	if (!line)
		return (NULL);
	free (temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*prev;
	
	buffer = prev;
	line = NULL;
	while (1)
	{
		if (!buffer)
			buffer = read_file(fd, buffer);
		if (!buffer)
			return (line);
		line = add_text(line, buffer);
		if (find_bline(buffer) == ft_strlen(buffer) && buffer[BUFFER_SIZE - 1] != '\n')
		{
			free(buffer);
			buffer = NULL;
			continue ;
		}
		else
		{
			prev = ft_strdup(ft_strchr(buffer, '\n'));
			return (line);
		}
	}
}

int main ()
{
	int fd = open("test.txt", O_RDONLY);
	int	i = 1;
	char *line;

	line = get_next_line(fd);
	while (line && i < 10)
	{
		printf("line [%d] :%s", i, line);
		line = get_next_line(fd);
		i++;
	}
	return (0);
}