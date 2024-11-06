/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:09:02 by pgrellie          #+#    #+#             */
/*   Updated: 2023/12/07 15:08:19 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_putchar_pf(int x);
int	ft_print_str(char *s);
int	ft_putnbr_base(long n, int base, int type);
int	ft_putunbr(unsigned int n);
int	ft_putptr(unsigned long long ptr);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

#endif
