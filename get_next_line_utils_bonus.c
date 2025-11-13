/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:42:20 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/13 12:42:22 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;
	int		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	buffer = malloc(size * nmemb);
	if (!buffer)
		return (NULL);
	i = -1;
	while (++i < size * nmemb)
		((unsigned char *)buffer)[i] = 0;
	return (buffer);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_t;
	size_t	len_s1;
	size_t	i;
	char	*a;

	len_s1 = ft_strlen(s1);
	len_t = len_s1 + ft_strlen(s2);
	a = ft_calloc(len_t + 1, sizeof(char));
	if (!a)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i])
			a[i] = s1[i];
		free(s1);
	}
	i = -1;
	while (s2[++i])
		a[i + len_s1] = s2[i];
	a[len_t] = 0;
	return (a);
}

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

int	append_line(char *temp, char **line, char **buffer)
{
	char	*new;

	if (temp)
	{
		*line = ft_strjoin(*line, temp);
		if (!*line)
			return (free(temp), 0);
		new = ft_strjoin(NULL, *buffer + ft_strlen(temp));
		if (!new)
			return (free(temp), 0);
		free(*buffer);
		free(temp);
		*buffer = new;
		return (1);
	}
	*line = ft_strjoin(*line, *buffer);
	if (!*line)
		return (0);
	free(*buffer);
	*buffer = NULL;
	return (0);
}

int	get_line(char **line, char **buffer)
{
	char	*temp;
	int		i;
	int		j;

	if (!*buffer)
		return (0);
	temp = NULL;
	i = -1;
	j = -1;
	while ((*buffer)[++i])
	{
		if ((*buffer)[i] == '\n')
		{
			i++;
			temp = ft_calloc(sizeof(char), i + 1);
			if (!temp)
				return (0);
			while (++j < i)
				temp[j] = (*buffer)[j];
			break ;
		}
	}
	return (append_line(temp, line, buffer));
}
