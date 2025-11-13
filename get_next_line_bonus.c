/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:40:38 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/13 20:43:30 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!get_line(&line, &buffer[fd]))
	{
		if (buffer[fd])
			return (free(buffer[fd]), buffer[fd] = NULL, free(line), NULL);
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer[fd])
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (read(fd, buffer[fd], BUFFER_SIZE) <= 0)
			return (free(buffer[fd]), buffer[fd] = NULL, line);
	}
	return (line);
}
