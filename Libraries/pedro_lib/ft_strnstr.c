/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:18:12 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/24 15:48:55 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	if ((!haystack || !needle) && !len)
		return (NULL);
	x = 0;
	y = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[x] != '\0' && x < len)
	{
		while (haystack[x + y] == needle[y]
			&& haystack[x + y] != '\0' && x + y < len)
		{
			y++;
			if (needle[y] == 0)
				return ((char *) haystack + x);
		}
		x++;
		y = 0;
	}
	return (0);
}
