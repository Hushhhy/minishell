/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:27:28 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/25 15:14:32 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_ms *ms)
{
	t_env		*current;
	int			i;

	current = ms->env;
	i = 1;
	while (ms->cmdlines->cmd->cmds[i])
	{
		current = ms->env;
		while (current)
		{
			if (ft_strcmp(ms->cmdlines->cmd->cmds[i], current->name) == 0)
			{
				delete_env(&ms->env, current);
				break ;
			}
			current = current->next;
		}
		i++;
	}
	return (0);
}
