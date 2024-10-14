/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:02:46 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/14 14:58:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
	exit(EXIT_FAILURE);
}

void	arg_not_found(char *s)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": command not found\n", 2);
}

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
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("syntax error near unexpected token '", 2);
			ft_putstr_fd(tok->next->value, 2);
			ft_putstr_fd("'\n", 2);
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
