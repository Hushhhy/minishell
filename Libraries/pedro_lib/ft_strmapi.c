/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:03:20 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/24 13:04:58 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	char			*ns;

	if (!s)
		return (NULL);
	ns = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!ns)
		return (NULL);
	x = 0;
	while (x < ft_strlen(s))
	{
		ns[x] = (*f)(x, s[x]);
		x++;
	}
	ns[x] = 0;
	return (ns);
}
