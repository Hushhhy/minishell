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
	size_t	len;
	char	*cpy;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	cpy = (char *)ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	x = 0;
	while (x < len)
	{
		cpy[x] = str[x];
		x++;
	}
	cpy[x] = '\0';
	return (cpy);
}
