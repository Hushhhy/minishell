/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:44:17 by pgrellie          #+#    #+#             */
/*   Updated: 2023/12/07 15:08:30 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int x)
{
	return (write(1, &x, 1));
}

static int	ft_putstr_pf(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		ft_putchar_pf(*s++);
		count++;
	}
	return (count);
}	

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (ft_putstr_pf("(null)"));
	while (*s != '\0')
	{
		ft_putchar_pf(*s++);
		count++;
	}
	return (count);
}

int	ft_putnbr_base(long n, int base, int type)
{
	int		count;
	char	*symbols;

	if (type == 0)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr_base(-n, base, type) + 1);
	}
	else if (n < base)
		return (ft_putchar_pf(symbols[n]));
	else
	{
		count = ft_putnbr_base(n / base, base, type);
		return (count + ft_putnbr_base(n % base, base, type));
	}
	return (count);
}
