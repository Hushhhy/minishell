/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:43:59 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/29 15:05:44 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_separator(char c, char next_c)
{
	if (c == '|' || c == '<' || c == '>'
		|| (c == '<' && next_c == '<')
		|| (c == '>' && next_c == '>'))
		return (true);
	else
		return (false);
}

bool	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

t_token	*find_last(t_token *tok)
{
	t_token	*tmp;

	tmp = tok;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	token_counter(t_token *tok)
{
	int	x;

	if (!tok)
		return (0);
	x = 0;
	while (tok)
	{
		x++;
		tok = tok->next;
	}
	return (x);
}
