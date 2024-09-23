/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:29:39 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/21 17:45:00 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	x;
	char	*s;

	x = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (x < len)
	{
		s[x] = str[start + x];
		x++;
	}
	return (s);
}
