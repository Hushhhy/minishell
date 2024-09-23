/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden_chars_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:14 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/06 16:59:38 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Implémentation de in_out_check
bool	in_out_check(void)
{
	return (true);
}

bool	is_forbiden_char(char c, char next_c, char next_next_c)
{
	return (c == '&' || c == ';' || c == '%'
		|| c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n'
		|| c == ',' || c == '(' || c == ')'
		|| (c == '&' && next_c == '&')
		|| (c == '|' && next_c == '|')
		|| (c == ';' && next_c == ';')
		|| (c == '|' && next_c == '&')
		|| (c == ';' && next_c == ';' && next_next_c == '&'));
}

bool	c_check(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (q_check(s) == true)
		{
			if (!is_quoted(s, x) && s[x + 1] != '\0'
				&& ((s[x + 2] != '\0'
						&& is_forbiden_char(s[x], s[x + 1], s[x + 2]))
					|| (s[x + 2] == '\0'
						&& is_forbiden_char(s[x], s[x + 1], '\0')))
				&& in_out_check() == true)
				return (false);
		}
		x++;
	}
	return (true);
}
