/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit_checker_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:19:14 by pgrellie          #+#    #+#             */
/*   Updated: 2024/08/28 17:57:45 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_isshit_1(char c, char next_c, char next_next_c)
{
	return (c == '|' || (c == '>' && next_c == '|')
		|| (c == '>' && next_c == ' ' && next_next_c == '|'));
}

bool	shit_check_1(char *s)
{
	int	x;

	x = 0;
	if (ft_isshit_1(s[x], s[x + 1], s[x + 2]))
		return (false);
	while (s[x])
		x++;
	x--;
	while (ft_isspace(s[x]))
		x--;
	if (s[x] == '|')
		return (false);
	else
		return (true);
}
