/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:07:57 by pgrellie          #+#    #+#             */
/*   Updated: 2023/12/07 15:15:26 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != '\0')
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_pf(ptr + '0');
		else
			ft_putchar_pf(ptr - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += write(1, "(nil)", 5);
	}
	else
	{
		count += write(1, "0x", 2);
		ft_put_ptr(ptr);
		count += ft_ptr_len(ptr);
	}
	return (count);
}
