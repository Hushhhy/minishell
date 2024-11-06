/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:02:34 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/04 16:09:25 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_and_free(t_ms *ms)
{
	if (ms->cmdlines)
		clear_cmdlines(&ms->cmdlines);
	if (ms->envi)
		ft_free_tab(ms->envi);
	if (ms->pid)
	{
		free(ms->pid);
		ms->pid = NULL;
	}
	close(ms->pipefd[0]);
	close(ms->pipefd[1]);
}
