/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:57:14 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/17 18:52:03 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	word_type_token(t_token *previous)
{
	if (previous == NULL)
		return (CMD);
	else if (previous != NULL && previous->type == INFILE)
		return (CMD);
	else if (previous != NULL && previous->type == PIPE)
		return (CMD);
	else if (previous != NULL && previous->type == REDIR_IN)
		return (INFILE);
	else if (previous != NULL && (previous->type == REDIR_OUT
			|| previous->type == APPEND))
		return (OUTFILE);
	else if (previous != NULL && previous->type == HERE_DOC)
		return (LIMITER);
	else
		return (WORD);
}

t_token_type	da_tok(char *s, t_token *previous)
{
	if (ft_strcmp(s, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(s, "<") == 0)
		return (REDIR_IN);
	else if (ft_strcmp(s, ">") == 0)
		return (REDIR_OUT);
	else if (ft_strcmp(s, "<<") == 0)
		return (HERE_DOC);
	else if (ft_strcmp(s, ">>") == 0)
		return (APPEND);
	else if (s[0] == ' ' && s[1] && s[1] == '-')
		return (ARG);
	else
		return (word_type_token(previous));
}

	// else if (ft_strchr(s, '=') != NULL)
	// 	return (LIMITER);

/* 
Deux possibilites d'ecriture dans le prompt :

1 :	< Makefile cat | wc -l > outf

2 :	cat < Makefile | wc -l > outf
*/