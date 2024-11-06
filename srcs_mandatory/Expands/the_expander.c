/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:44:40 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/30 15:46:48 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander(t_ms *ms)
{
	t_token	*current;

	if (!ms || !ms->tokens)
		return ;
	current = ms->tokens;
	while (current)
	{
		current->to_del = false;
		if (current->prev && current->prev->type == HERE_DOC)
		{
			finishing(current);
			current = current->next;
			continue ;
		}
		if (current->value)
		{
			dr_kron(current, ms->env, ms->v_return);
			finishing(current);
		}
		current = current->next;
	}
}
