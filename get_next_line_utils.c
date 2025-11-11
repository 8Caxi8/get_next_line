/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:52:36 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/10 17:34:13 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*a;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	a = malloc(len + 2);
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, len + 1);
	ft_strlcat(a, s2, len + 2);
	return (a);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *) src);
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] && i + dest_len < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
		if (src[i - 1] == '\n')
			break ;
	}
	while (i + dest_len < size)
	{
		dest[dest_len + i] = 0;
		i++;
	}
	return (dest_len + src_len);
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
