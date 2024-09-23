/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:56:41 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/23 14:35:39 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] != '\0' && x < n - 1)
	{
			x++;
	}
	return ((unsigned char)(s1[x]) - (unsigned char)(s2[x]));
}
