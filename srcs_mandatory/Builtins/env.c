/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:57:06 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/21 18:06:03 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(t_cmdline *cmdline, t_ms *ms)
{
	int	i;

	i = 0;
	if (cmdline->cmd->cmds[1])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
		return (1);
	}
	while (ms->envi[i])
	{
		ft_putstr_fd(ms->envi[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}
