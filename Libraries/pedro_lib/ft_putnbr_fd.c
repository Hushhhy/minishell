/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:05:45 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/23 16:24:32 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	z;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		z = (unsigned int)(n * -1);
	}
	else
		z = (unsigned int)n;
	if (z >= 10)
	{
		ft_putnbr_fd(z / 10, fd);
		z %= 10;
	}
	ft_putchar_fd(z + 48, fd);
}
