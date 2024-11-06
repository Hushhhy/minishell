/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:15:33 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/06 15:21:29 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	not_a_nbr(t_ms *ms, t_cmdline *cmdline)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit :", 2);
	ft_putstr_fd(cmdline->cmd->cmds[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	clear_program(ms);
	exit(2);
}

int	ft_exit(t_cmdline *cmdline, t_ms *ms)
{
	static int	exit_stat = 0;

	if (!cmdline->cmd->cmds[1])
	{
		printf("exit\n");
		clear_program(ms);
		exit(1);
	}
	if (!is_num(cmdline->cmd->cmds[1]))
		not_a_nbr(ms, cmdline);
	if (cmdline->cmd->cmds[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	if (is_num(cmdline->cmd->cmds[1]))
	{
		printf("exit\n");
		exit_stat = ft_atoi(cmdline->cmd->cmds[1]);
		clear_program(ms);
		exit(exit_stat);
	}
	exit(exit_stat);
}
