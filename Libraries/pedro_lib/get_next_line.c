/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:32:12 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/13 18:20:48 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	char		*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(s);
		free(buf);
		s = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line_buffer(fd, s, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	s = set_line(line);
	return (line);
}

char	*fill_line_buffer(int fd, char *s, char *buf)
{
	ssize_t	bytes_readed;
	char	*tmp;

	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(s);
			return (NULL);
		}
		else if (bytes_readed == 0)
			break ;
		buf[bytes_readed] = '\0';
		if (!s)
			s = ft_strdup_gnl("");
		tmp = s;
		s = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr_gnl(buf, '\n'))
			break ;
	}
	return (s);
}

char	*set_line(char *s_buf)
{
	char	*s;
	ssize_t	x;

	x = 0;
	while (s_buf[x] != '\n' && s_buf[x] != '\0')
		x++;
	if (s_buf[x] == '\0' || s_buf[x + 1] == '\0')
		return (NULL);
	s = ft_substr_gnl(s_buf, x + 1, ft_strlen_gnl(s_buf) - x);
	if (s == NULL)
		return (NULL);
	if (*s == 0)
	{
		free(s);
		s = NULL;
	}
	s_buf[x + 1] = '\0';
	return (s);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*element;

	if (size != 0 && count > (size_t) - 1 / size)
		return (NULL);
	element = malloc(count * size);
	if (!element)
		return (NULL);
	ft_bzero_gnl(element, (count * size));
	return (element);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			x;

	dest = s;
	x = 0;
	while (x < n)
	{
		*dest = 0;
		dest++;
		x++;
	}
}
