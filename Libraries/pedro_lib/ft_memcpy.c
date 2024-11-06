/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:34:55 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/24 15:38:15 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;
	char	*str;

	if (!dst && !src)
		return (NULL);
	str = (char *)dst;
	x = 0;
	while (x < n)
	{
		*(char *)str = *(char *)src;
		str++;
		src++;
		x++;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    char    *src = "La casa de la bendita margarita";
    char dest[50];

    ft_memcpy(dest, src, strlen(src) + 1);
    printf("ft_memcpy : %s\n", dest);

    char    dest_std[50];
    memcpy(dest_std, src, strlen(src) + 1);
    printf("memcpy : %s\n", dest_std);

    return (0);
}*/
