/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:28:17 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/02 01:28:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(t_ms *ms)
{
	t_cmdline	*current;

	current = ms->cmdlines;
	if (current)
	{
		if (ft_strcmp(current->cmd->cmds[0], "echo") == 0)
		{
			ms->b = true;
			return (ft_echo(ms->cmdlines));
		}
		else if (ft_strcmp(current->cmd->cmds[0], "cd") == 0)
		{
			ms->b = true;
			return (ft_cd(current, ms));
		}
		else if (ft_strcmp(current->cmd->cmds[0], "exit") == 0)
		{
			ms->b = true;
			return (ft_exit(current, ms));
		}
		if (builtins_part(ms, current))
			return (1);
	}
	return (0);
}

int	builtins_part(t_ms *ms, t_cmdline *current)
{
	if (ft_strcmp(current->cmd->cmds[0], "env") == 0)
	{
		ms->b = true;
		return (print_env(current, ms));
	}
	else if (ft_strcmp(current->cmd->cmds[0], "pwd") == 0)
	{
		ms->b = true;
		return (ft_pwd(ms));
	}
	else if (ft_strcmp(current->cmd->cmds[0], "unset") == 0)
	{
		ms->b = true;
		return (ft_unset(ms));
	}
	else if (ft_strcmp(current->cmd->cmds[0], "export") == 0)
	{
		ms->b = true;
		return (ft_export(ms));
	}
	return (0);
}

int	builtins_checker(t_ms *ms)
{
	t_cmdline	*current;

	current = ms->cmdlines;
	if (current)
	{
		if (ft_strcmp(current->cmd->cmds[0], "unset") == 0)
			return (0);
		else if (ft_strcmp(current->cmd->cmds[0], "export") == 0)
			return (0);
		else if (ft_strcmp(current->cmd->cmds[0], "pwd") == 0)
			return (0);
		else if (ft_strcmp(current->cmd->cmds[0], "exit") == 0)
			return (0);
		else if (ft_strcmp(current->cmd->cmds[0], "cd") == 0)
			return (0);
	}
	return (1);
}

int	mini_builtins(t_ms *ms)
{
	t_cmdline	*current;

	current = ms->cmdlines;
	if (ft_strcmp(current->cmd->cmds[0], "unset") == 0)
	{
		ms->b = true;
		return (ft_unset(ms));
	}
	else if (ft_strcmp(current->cmd->cmds[0], "export") == 0)
	{
		ms->b = true;
		return (ft_export(ms));
	}
	else if (ft_strcmp(current->cmd->cmds[0], "pwd") == 0)
	{
		ms->b = true;
		return (ft_pwd(ms));
	}
	if (mini_builtins_parts(ms, current))
		return (1);
	return (0);
}

int	mini_builtins_parts(t_ms *ms, t_cmdline *current)
{
	if (ft_strcmp(current->cmd->cmds[0], "exit") == 0)
	{
		ms->b = true;
		return (ft_exit(current, ms));
	}
	else if (ft_strcmp(current->cmd->cmds[0], "cd") == 0)
	{
		ms->b = true;
		return (ft_cd(current, ms));
	}
	return (0);
}
