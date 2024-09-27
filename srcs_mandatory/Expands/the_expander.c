/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:44:40 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/27 18:52:51 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander(t_ms *ms)
{
	while (ms->tokens)
	{
		if (ms->tokens->type == WORD || ms->tokens->type == INFILE
			|| ms->tokens->type == OUTFILE
			|| (ms->tokens->type == CMD && ms->tokens->prev == NULL))
		{
			if (ms->tokens->value)
			{
				dr_kron(ms->tokens, ms->env, ms->v_return);
				finishing(ms->tokens);
				display_tokens(ms->tokens);
			}
		}
		ms->tokens = ms->tokens->next;
	}
}
