/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:26:16 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/10 18:59:11 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

void	*ft_memchr(const void *str, int chr, size_t n)
{
	unsigned char	*s;
	unsigned char	c;
	size_t			x;

	s = (unsigned char *)str;
	c = (unsigned char)chr;
	x = 0;
	while (x < n)
	{
		if (s[x] == c)
			return ((void *) &s[x]);
		x++;
	}
	return (NULL);
}
