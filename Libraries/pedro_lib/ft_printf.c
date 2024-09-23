/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:30:11 by pgrellie          #+#    #+#             */
/*   Updated: 2024/05/13 18:15:47 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_pf(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str((char *)va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr_base((long)va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		count += ft_putunbr((long)va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, unsigned long long));
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/*int	main(void)
{
	int	count;

	count = ft_printf("Hello %s\n", "Pedro");
	ft_printf("Les caracteres %d\n", count);
	return (0);
}*/
