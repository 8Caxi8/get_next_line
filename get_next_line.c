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

char	*next_endl(const char *src, char c)
{
	int		i;
	char	*next;

	if (!src)
		return (NULL);
	while (*src)
	{
		if (*src == c)
			break ;
		src++;
	}
	if (*src == 0 || *(src + 1)  == 0)
		return (NULL);
	src++;
	next = malloc (sizeof(char) * (ft_strlen(src) + 1));
	if (!next)
		return (NULL);
	i = -1;
	while (src[++i])
		next[i] = src[i];
	next[i] = '\0';
	return (next);
}

size_t	find_bline(char *buffer)
{
	size_t	len;

	len = 0;
	if (buffer)
	{
		while (buffer[len] && len < BUFFER_SIZE + 1)
		{
			if (buffer[len] == '\n')
				break ;
		len++;
		}
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
	{
		free (buffer);
		return (NULL);
	}
	return (buffer);
}
char	*add_text(char *line, char *buffer)
{
	char	*temp;
	
	temp = line;
	line = ft_strjoin(temp,  buffer);
	if (!line)
		return (NULL);
	if (temp)
		free (temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*next;
	
	buffer = next;
	line = NULL;
	while (1)
	{
		if (!buffer)
			buffer = read_file(fd, buffer);
		if (!buffer)
			return (line);
		line = add_text(line, buffer);
		if (find_bline(buffer) == ft_strlen(buffer) && buffer[ft_strlen(buffer) - 1] != '\n')
		{
			free(buffer);
			buffer = NULL;
			next = NULL;
		}
		else
		{
			next = next_endl(buffer, '\n');
			free(buffer);
			return (line);
		}
	}
}
