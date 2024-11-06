/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:11:47 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/28 15:47:55 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirs_counter(t_token *tok)
{
	t_token	*current;
	int		x;

	x = 0;
	current = tok;
	while (current && current->type != PIPE)
	{
		if (current->type == REDIR_IN || current->type == REDIR_OUT
			|| current->type == APPEND || current->type == HERE_DOC)
		{
			x += 1;
			current = current->next;
		}
		if (current)
			current = current->next;
	}
	return (x);
}

t_redirs	*the_redirs(t_token *tok)
{
	t_token		*current;
	t_redirs	*redirs;

	current = tok;
	redirs = NULL;
	while (current && current->type != PIPE)
	{
		if (current->type == REDIR_IN || current->type == REDIR_OUT
			|| current->type == APPEND || current->type == HERE_DOC)
		{
			add_redirs_node(&redirs, current);
			current = current->next;
		}
		if (current)
			current = current->next;
	}
	return (redirs);
}

int	cmd_counter(t_token *tok)
{
	t_token	*current;
	int		x;

	x = 0;
	current = tok;
	while (current && current->type != PIPE)
	{
		if (current->type == CMD || current->type == ARG
			|| current->type == WORD)
			x += 1;
		current = current->next;
	}
	return (x);
}

char	**the_cmds(t_token *tok)
{
	t_token	*current;
	char	**cmds;
	int		y;

	y = 0;
	current = tok;
	cmds = ft_calloc(cmd_counter(tok) + 1, sizeof(char *));
	if (!cmds)
		return (NULL);
	while (current && current->type != PIPE)
	{
		if (current->type == CMD || current->type == ARG
			|| current->type == WORD)
		{
			cmds[y] = ft_strdup(current->value);
			if (!cmds[y])
				return (ft_free_tab(cmds), NULL);
			y++;
		}
		current = current->next;
	}
	cmds[y] = NULL;
	return (cmds);
}

void	the_cmdlines(t_ms *ms)
{
	t_token		*current;

	current = ms->tokens;
	while (current)
	{
		add_cmdline_node(&ms->cmdlines, current);
		while (current && current->type != PIPE)
			current = current->next;
		if (current)
			current = current->next;
		if (!current)
			break ;
	}
}
