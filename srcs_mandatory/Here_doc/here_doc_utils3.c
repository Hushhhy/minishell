/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:07:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/06 15:01:14 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_std(int saved_stdin)
{
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	return ;
}

void	clean_hd_child(t_ms *ms)
{
	close_all_fds();
	free_tokens(&ms->tokens);
	free_env(&ms->env);
	free(ms->prompt);
	ms->prompt = NULL;
	free(ms);
}

void	clear_program(t_ms *ms)
{
	close_all_fds();
	if (ms->cmdlines)
		clear_cmdlines(&ms->cmdlines);
	if (ms->envi)
		ft_free_tab(ms->envi);
	if (ms->tokens)
		free_tokens(&ms->tokens);
	if (ms->env)
		free_env(&ms->env);
	if (ms->prompt)
	{
		free(ms->prompt);
		ms->prompt = NULL;
	}
	if (ms->pid)
	{
		free(ms->pid);
		ms->pid = NULL;
	}
	if (ms)
		free(ms);
}

void	clear_program_hd(t_ms *ms)
{
	close_all_fds();
	if (ms->cmdlines)
		clear_cmdlines(&ms->cmdlines);
	if (ms->tokens)
		free_tokens(&ms->tokens);
	if (ms->env)
		free_env(&ms->env);
	if (ms->prompt)
	{
		free(ms->prompt);
		ms->prompt = NULL;
	}
	if (ms)
		free(ms);
}
