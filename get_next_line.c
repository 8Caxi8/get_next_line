/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:49:04 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/12 16:49:17 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = NULL;
	while (!get_line(&line, &buffer))
	{
		if (buffer)
			return (free(buffer), NULL);
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (free(line), NULL);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (free(buffer), buffer = NULL, line);
	}
	return (line);
}
