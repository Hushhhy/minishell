/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:35:22 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/23 16:37:48 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	x;

	if (!dst && !src)
		return (0);
	x = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		x = len - 1;
		while (x < len)
		{
			((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
			x--;
		}
	}
	else
	{
		while (x < len)
		{
			((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
			x++;
		}
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    char    *srs = "La casa de la bendita maragarita";
    char    dst[50];

    ft_memmove(dst, srs, strlen(srs) + 1);
    printf("ft_memmove : %s\n", dst);

    memmove(dst, srs, strlen(srs) + 1);
    printf("memmove : %s\n", dst);
    return (0);
}*/
