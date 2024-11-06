/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_in_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 17:06:47 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_child(t_ms *ms)
{
	if (ms->cmdlines)
		clear_cmdlines(&ms->cmdlines);
	if (ms->tokens)
		free_tokens(&ms->tokens);
	if (ms->env)
		free_env(&ms->env);
	if (ms->envi)
		ft_free_tab(ms->envi);
	if (ms->pid)
	{
		free(ms->pid);
		ms->pid = NULL;
	}
	close_all_fds();
	if (ms->prompt)
	{
		free(ms->prompt);
		ms->prompt = NULL;
	}
	free(ms);
}

char	*env_for_exec(char **envi, char *cmd)
{
	int		x;
	char	*path;
	char	*tmp;

	x = 0;
	while (envi[x])
	{
		path = ft_strjoin(envi[x], "/");
		tmp = path;
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_tab(envi);
			return (path);
		}
		free(path);
		path = NULL;
		x++;
	}
	ft_free_tab(envi);
	return (NULL);
}

void	cmd_exec(t_ms *ms, char *cmd)
{
	if (cmd == NULL || ft_strlen(cmd) == 0
		|| ft_strcmp(ms->cmdlines->cmd->cmds[0], ".") == 0
		|| ft_strcmp(ms->cmdlines->cmd->cmds[0], "..") == 0)
	{
		ft_putstr_fd("MYSHELL: command not found\n", 2);
		clean_child(ms);
		exit(127);
	}
	cmd = cmd_path(ms->envi, ms->cmdlines->cmd->cmds[0], ms);
	if (cmd)
	{
		execve(cmd, ms->cmdlines->cmd->cmds, ms->envi);
		free(cmd);
		cmd = NULL;
		clean_child(ms);
		handle_exec_error(ms);
	}
	else
	{
		ft_putstr_fd("MYSHELL : ", 2);
		ft_putstr_fd(ms->cmdlines->cmd->cmds[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		clean_child(ms);
		exit(127);
	}
}

void	child_process(t_ms *ms)
{
	redirector(ms);
	ft_open_files(ms);
	ms->v_return = builtins(ms);
	if (ms->b == true)
	{
		clean_child(ms);
		exit(0);
	}
	if (ms->cmdlines->cmd->cmds[0])
		cmd_exec(ms, ms->cmdlines->cmd->cmds[0]);
	clean_child(ms);
	exit(0);
}
