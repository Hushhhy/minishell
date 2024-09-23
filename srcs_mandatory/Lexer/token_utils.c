/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:43:59 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/17 18:26:28 by pgrellie         ###   ########.fr       */
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


// int	token_len(t_token *tok)
// {
// 	int	x;

// 	if (!tok)
// 		return (0);
// 	x = 0;
// 	while (tok)
// 	{
// 		tok = tok->next;
// 		x++;
// 	}
// 	return (x);
// }
