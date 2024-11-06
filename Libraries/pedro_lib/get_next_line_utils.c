/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:35:17 by pgrellie          #+#    #+#             */
/*   Updated: 2024/05/21 14:02:14 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen_gnl(const char *str)
{
	unsigned int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strchr_gnl(const char *str, int chr)
{
	unsigned int	x;
	unsigned char	c;

	x = 0;
	c = chr;
	while (str[x] != '\0')
	{
		if (str[x] == c)
			return ((char *)&str[x]);
		x++;
	}
	if (str[x] == c)
		return ((char *)&str[x]);
	else
		return (NULL);
}

char	*ft_strdup_gnl(const char *str)
{
	size_t	x;
	char	*cpy;

	x = 0;
	cpy = (char *)malloc(ft_strlen_gnl(str) + 1);
	if (!cpy)
		return (NULL);
	while (str[x] != '\0')
	{
		cpy[x] = str[x];
		x++;
	}
	cpy[x] = 0;
	return (cpy);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	x;
	size_t	y;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char)
			* (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x] != '\0')
	{
		str[y++] = s1[x++];
	}
	x = 0;
	while (s2[x] != '\0')
	{
		str[y++] = s2[x++];
	}
	str[y] = '\0';
	return (str);
}

char	*ft_substr_gnl(const char *str, unsigned int start, size_t len)
{
	size_t	x;
	char	*s;

	x = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen_gnl(str))
		return (ft_strdup_gnl(""));
	if (len > ft_strlen_gnl(str + start))
		len = ft_strlen_gnl(str + start);
	s = ft_calloc_gnl(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (x < len)
	{
		s[x] = str[start + x];
		x++;
	}
	return (s);
}
