/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:35:04 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/24 16:12:18 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	y;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!str)
		return (free(str), NULL);
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
	// str[y++] = ' ';
