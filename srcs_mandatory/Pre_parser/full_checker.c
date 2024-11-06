/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:44:59 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/06 15:02:35 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*epure_tokens(t_ms *ms)
{
	t_token	*current;
	t_token	*temp;

	if (!ms || !ms->tokens)
		return (NULL);
	current = ms->tokens;
	while (current)
	{
		if (current->to_del)
		{
			temp = current->next;
			delete_token(&ms->tokens, current);
			current = temp;
		}
		else
		{
			current = current->next;
		}
	}
	return (ms->tokens);
}

bool	full_check(t_ms *ms)
{
	if (q_check(ms->prompt) == false || c_check(ms->prompt) == false
		|| shit_check_1(ms->prompt) == false)
	{
		free(ms->prompt);
		ms->prompt = NULL;
		free_tokens(&ms->tokens);
		ft_putstr_fd("bash: syntax error near unexpected token `;'\n", 2);
		return (false);
	}
	else
	{
		ms->tokens = lexer(ms->prompt);
		expander(ms);
		epure_tokens(ms);
		if (_redirs_checker(ms) == false)
		{
			false_redirs(ms);
			return (false);
		}
		else
			return (true);
	}
}

void	false_redirs(t_ms *ms)
{
	free(ms->prompt);
	ms->prompt = NULL;
	free_tokens(&ms->tokens);
	ft_putstr_fd("MYSHELL: syntax error near unexpected token `newline'\n", 2);
	ms->v_return = 2;
}
