/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:09:37 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/03 18:14:56 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

size_t	ft_strlen(const char *s)
{
	unsigned long int	x;

	x = 0;
	if (!s)
		return (-1);
	while (s[x] != '\0')
		x++;
	return (x);
}
