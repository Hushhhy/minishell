/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:38:47 by pgrellie          #+#    #+#             */
/*   Updated: 2023/12/07 15:08:08 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_numlen(n);
	num = (char *) malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (num);
}

int	ft_putunbr(unsigned int n)
{
	char	*num;
	int		count;

	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		count += ft_print_str(num);
		free(num);
	}
	return (count);
}
