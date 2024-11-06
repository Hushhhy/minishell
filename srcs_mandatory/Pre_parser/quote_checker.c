/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:17:11 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/02 16:45:58 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	q_check(char *s)
{
	char	quote;
	int		x;

	if (!s)
		return (false);
	x = 0;
	quote = 'K';
	while (s[x])
	{
		if (s[x] == '\"' && quote == 'K')
			quote = '\"';
		else if (s[x] == '\'' && quote == 'K')
			quote = '\'';
		else if (s[x] == '\"' && quote == '\"')
			quote = 'K';
		else if (s[x] == '\'' && quote == '\'')
			quote = 'K';
		x++;
	}
	if (quote == 'K')
		return (true);
	else
		return (false);
}

//index means position
bool	is_quoted(char *s, int index)
{
	bool	in_single_quote;
	bool	in_double_quote;
	int		x;

	in_single_quote = false;
	in_double_quote = false;
	x = 0;
	while (x < index)
	{
		if (s[x] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (s[x] == '\"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		x++;
	}
	return (in_single_quote || in_double_quote);
}
