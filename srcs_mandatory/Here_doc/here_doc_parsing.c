/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:14:53 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/16 14:39:36 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_here_doc(t_token *tok)
{
	if (tok)
	{
		if (tok->type == HERE_DOC && !tok->next)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
			return (1);
		}
		if (tok->type == HERE_DOC && tok->next->type == LIMITER)
		{
			if (start_pipe(tok->next->value))
				return (1);
			tok = tok->next;
			if (tok->next && tok->next->type != HERE_DOC)
				arg_not_found(tok->next->value);
		}
		else if (tok->type == HERE_DOC && tok->next->type != LIMITER)
		{
			syntax_error(tok);
            return (1);
		}
	}
	return (0);
}

void	here_doc_count(t_token *tok)
{
	t_token	*here;
	int		i;

	here = tok;
	i = 1;
	while (here)
	{
		if (here->type == HERE_DOC)
		{
			if (i == 17)
			{
				ft_putstr_fd("minishell: maximum here-document ", 2);
				ft_putstr_fd("count exceeded\n", 2);
				exit(2);
			}
			i++;
		}
		here = here->next;
	}
}

bool	line_error(int l, char *line, char *limiter)
{	
	char	*lc;

	lc = NULL;
	if (!line)
	{
		lc = ft_itoa(l);
		ft_putstr_fd("minishell: warning: ", 2);
		ft_putstr_fd("here-document at line ", 2);
		ft_putstr_fd(lc, 2);
		ft_putstr_fd(" delimited by end-of-file (wanted '", 2);
		ft_putstr_fd(limiter, 2);
		ft_putstr_fd("')\n", 2);
		return (true);
	}
	return (false);
}
