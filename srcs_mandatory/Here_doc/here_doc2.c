/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:33:18 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/03 13:27:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_here_doc(t_ms *ms, t_token, *tok)
{
	int		fd[2];
	char	*line;

	if (!has_here_doc(tok))
		return ;
	pipe(fd);
	handle_here_doc_signals();
	while (true)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, get_imiter(tok)) == 0)
			break ;
		free(line);
	}
	free (line);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}

int	has_here_doc(t_token *tok)
{
	t_token	*cur;

	cur = tok;
	while (cur)
	{
		if (cur->type == HERE_DOC)
			return (1);
		cur = cur->next;
	}
	return (0);
}

char	*get_limiter(t_token *tok)
{
	t_token	*cur;

	cur = tok;
	while (cur)
	{
		if (cur->type == HERE_DOC && cur->next && cur->next->type == LIMITER)
			return (cur->next->value);
		cur = cur->next;
	}
	return (NULL);
}
