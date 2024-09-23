/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:43:20 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/10 19:00:31 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

char	*ft_strchr(const char *str, int chr)
{
	unsigned int	x;
	unsigned char	c;

	x = 0;
	c = chr;
	while (str[x] != '\0')
	{
		if (str[x] == c)
			return ((char *) &str[x]);
		x++;
	}
	if (str[x] == c)
		return ((char *) &str[x]);
	else
		return (NULL);
}
