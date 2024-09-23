/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:02:05 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/17 18:48:30 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				x;
	const unsigned char	*str1;
	const unsigned char	*str2;

	x = 0;
	str1 = s1;
	str2 = s2;
	while (x < n)
	{
		if (str1[x] != str2[x])
			return (str1[x] - str2[x]);
		x++;
	}
	return (0);
}
