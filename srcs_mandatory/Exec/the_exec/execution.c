/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:47:02 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 17:10:25 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	readme_mf(t_cmdline *cmdline)
{
	if (cmdline->cmd->cmds
		&& ft_strcmp(cmdline->cmd->cmds[0], "README.md") == 0)
	{
		ft_putstr_fd("MYSHELL: Permission denied\n", 2);
		return (false);
	}
	else
		return (true);
}

void	fd_manager(t_ms *ms, int x)
{
	close(ms->pipefd[1]);
	if (x > 0)
		close(ms->previous_fd);
	ms->previous_fd = ms->pipefd[0];
}

int	bb_executioner(t_ms *ms)
{
	int	v_ret;

	v_ret = 0;
	if (builtins_checker(ms) == 0)
	{
		ms->pid[0] = fork();
		if (ms->pid[0] == -1)
		{
			clean_child(ms);
			exit(1);
		}
		if (ms->pid[0] == 0)
		{
			ft_open_files(ms);
			clean_child(ms);
			exit(0);
		}
		v_ret = mini_builtins(ms);
		return (waiting_(ms, v_ret));
	}
	return (v_ret);
}

int	executioner(t_ms *ms)
{
	int			x;
	t_cmdline	*head;

	x = 0;
	head = ms->cmdlines;
	while (ms->cmdlines)
	{
		pipe(ms->pipefd);
		ms->pid[x] = fork();
		if (ms->pid[x] == -1)
		{
			clean_child(ms);
			exit(1);
		}
		signal(SIGQUIT, ft_sigquit_child);
		signal(SIGINT, child_sigint);
		if (ms->pid[x] == 0)
			child_process(ms);
		else
			fd_manager(ms, x);
		ms->cmdlines = ms->cmdlines->next;
		x++;
	}
	ms->cmdlines = head;
	return (wait_da_boy(ms));
}

int	executor(t_ms *ms)
{
	int	v_return;

	v_return = 0;
	if (ms->hd == true)
		return (130);
	ms->envi = the_env(ms->env);
	if (ms->envi == NULL)
	{
		ft_putstr_fd("Error: couldn't allocate memory\n", 2);
		return (1);
	}
	the_cmdlines(ms);
	ms->c_count = cmdlines_counter(ms->cmdlines);
	ms->pid = malloc(sizeof(int) * ms->c_count);
	if (!ms->pid)
		return (ft_putstr_fd("Error : malloc failed", 2), 1);
	if (ms->c_count == 1)
		v_return = bb_executioner(ms);
	if (ms->b == false)
		v_return = executioner(ms);
	close_and_free(ms);
	return (v_return);
}
