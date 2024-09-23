/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:04 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/11 18:23:55 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

// static char	*mem_alloc(char *s)
// {	
// 	s = malloc(sizeof(char) * 8);
// 	if (!s)
// 		return (NULL);
// 	return (s);
// }

// static char zero_filter(char *s)
// {
// 	int	x;
// 	char *res;

// 	x = 0;
// 	mem_alloc(res);
// 	if (s[x] == '0')
// 	{
// 		while (s[x] == '0' && s[x + 1] != '\0')
// 		{
// 			if ((s[x] == 0 && ft_isspace(s[x + 1]))
// 				|| (s[x] == 0 && s[x + 1] == '\0'))
// 			{
// 				res = "0\0";
// 				return (res);
// 			}
// 			x++;
// 		}
// 		while (s[x] != '\0')
// 		{
// 			res[x] == s[x];
// 			x++;
// 		}
// 		res[x] = '\0';
// 	}
// 	return (res);
// }

int	ft_atoi(const char *str)
{
	int	x;
	int	sign;
	int	res;

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
