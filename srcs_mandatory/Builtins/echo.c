/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:33:38 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/24 15:56:18 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	only_n(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' && s[1] == 'n')
		i += 2;
	while (s[i])
	{
		if (s[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	echo_utils(t_cmdline *cmdline, int i, int nl)
{
	i++;
	if (only_n(cmdline->cmd->cmds[i]))
	{
		i++;
		nl = 0;
	}
	while (cmdline->cmd->cmds[i]
		&& (ft_strcmp(cmdline->cmd->cmds[i], "|") != 0))
	{
		ft_putstr_fd(cmdline->cmd->cmds[i], 1);
		if (cmdline->cmd->cmds[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (nl)
		ft_putstr_fd("\n", 1);
}

int	ft_echo(t_cmdline *cmdline)
{
	int	nl;
	int	i;

	nl = 1;
	i = 0;
	if (cmdline->cmd->cmds[1])
		echo_utils(cmdline, i, nl);
	else
		ft_putstr_fd("\n", 1);
	return (0);
}
