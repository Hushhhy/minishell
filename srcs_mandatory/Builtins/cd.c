/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:12:43 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/26 15:12:43 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	no_dir(t_ms *ms)
{
	ft_putstr_fd("minishell: cd: Error retrieving current directory\n", 2);
	chdir(get_env_pwd("OLDPWD", ms));
	return (1);
}

void	update_pwd(char *new, t_ms *ms)
{
	t_env	*cur;

	cur = ms->env;
	while (cur)
	{
		if (ft_strcmp(cur->name, "PWD") == 0)
		{
			free(cur->value);
			cur->value = ft_strdup(new);
			return ;
		}
		cur = cur->next;
	}
	add_env(&cur, new);
}

int	changedir(char *path, t_ms *ms)
{
	char		*new;

	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	else
	{
		new = getcwd(NULL, 0);
		if (new)
		{
			update_pwd(new, ms);
			free(new);
		}
		else
			return (no_dir(ms));
	}
	return (0);
}

int	ft_cd(t_cmdline *cmdline, t_ms *ms)
{
	if (!cmdline->cmd->cmds[1])
		changedir(getenv("HOME"), ms);
	else if (cmdline->cmd->cmds[1])
	{
		if (cmdline->cmd->cmds[2])
		{
			ft_putstr_fd("minishel: cd: too many arguments\n", 2);
			return (1);
		}
		else if (changedir(cmdline->cmd->cmds[1], ms))
			return (1);
	}
	else
	{
		ft_putstr_fd("minishell: cd: usage: cd <path>\n", 2);
		return (1);
	}
	return (0);
}
