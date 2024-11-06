/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:37:53 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/17 18:06:51 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

int	ft_isalpha(int x)
{
	if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int main(void)
{
	int x = 'X';
	int p = '&';

	printf("X = %d\nP = %d\n", ft_isalpha(x), ft_isalpha(p));
	
	return(0);
}*/
