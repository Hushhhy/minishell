/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:16:07 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/28 17:42:53 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	p;
	size_t	w;

	if ((!dest || !src) && !dstsize)
		return (0);
	if (dstsize <= ft_strlen(dest))
		return (dstsize + ft_strlen(src));
	p = ft_strlen(dest);
	w = 0;
	while (src[w] != '\0' && p + 1 < dstsize)
	{
		dest[p] = src[w];
		p++;
		w++;
	}
	dest[p] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[w]));
}
