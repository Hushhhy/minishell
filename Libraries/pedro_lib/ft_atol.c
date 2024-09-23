/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:27:30 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/12 16:03:27 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

long	ft_atol(const char *str)
{
	int		x;
	int		sign;
	long	res;

	x = 0;
	sign = 1;
	res = 0;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = (str[x] - '0') + res * 10;
		x++;
	}
	return (res * sign);
}
