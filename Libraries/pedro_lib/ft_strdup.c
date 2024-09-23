/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:30:37 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/21 17:40:29 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

char	*ft_strdup(const char *str)
{
	size_t	x;
	char	*cpy;

	if (!str)
		return (NULL);
	x = 0;
	cpy = (char *)malloc(ft_strlen(str) + 1);
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
