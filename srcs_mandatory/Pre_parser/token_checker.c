/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:43 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/24 14:38:11 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redir_in_checker(t_ms *ms)
{
	t_token	*current;

	current = ms->tokens;
	while (current)
	{
		if (current->type == REDIR_IN)
		{
			if (!current->next || current->next->type != INFILE)
				return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	redir_out_checker(t_ms *ms)
{
	t_token	*current;

	current = ms->tokens;
	while (current)
	{
		if (current->type == REDIR_OUT)
		{
			if (!current->next || current->next->type != OUTFILE)
				return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	redir_app_checker(t_ms *ms)
{
	t_token	*current;

	current = ms->tokens;
	while (current)
	{
		if (current->type == APPEND)
		{
			if (!current->next || current->next->type != OUTFILE)
				return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	redir_hd_checker(t_ms *ms)
{
	t_token	*current;

	current = ms->tokens;
	while (current)
	{
		if (current->type == HERE_DOC)
		{
			if (!current->next || current->next->type != LIMITER)
				return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	_redirs_checker(t_ms *ms)
{
	if (!redir_in_checker(ms) || !redir_out_checker(ms)
		|| !redir_app_checker(ms) || !redir_hd_checker(ms))
		return (false);
	return (true);
}
