/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:55 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/08 14:45:31 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	papa_proces(pid_t pid, int pipefd[2])
{
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
	close(pipefd[0]);
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
		return (false);
	}
	return (true);
}

void	read_until_limit(char *limiteur, int pipefd)
{
	char	*line;
	int		sig_val;
	int		l;

	rl_outstream = stderr;
	sig_val = SIGINT;
	l = 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_here_doc);
	while (1)
	{
		line = readline("> ");
		if (line_error(l, line, limiteur) == false)
			break ;
		else if (ft_strcmp(line, limiteur) == 0)
		{
			free(line);
			break ;
		}
		l++;
		free(line);
	}
	close(pipefd);
	exit(0);
}

void	start_pipe(char *limiteur)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		close_pipe(pipefd[0], pipefd[1]);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close_pipe(pipefd[0], pipefd[1]);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		read_until_limit(limiteur, pipefd[1]);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		papa_proces(pid, pipefd);
	}
}

void	handle_here_doc(t_token *tok)
{
	if (tok)
	{
		if (tok->type == HERE_DOC && !tok->next)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
			return ;
		}
		if (tok->type == HERE_DOC && tok->next->type == LIMITER)
		{
			start_pipe(tok->next->value);
			signal(SIGINT, ft_sigint_handler);
			tok = tok->next;
			if (tok->next)
				arg_not_found(tok->next->value);
		}
		else if (tok->type == HERE_DOC && tok->next->type != LIMITER)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("syntax error near unexpected token '", 2);
			ft_putstr_fd(tok->next->value, 2);
			ft_putstr_fd("'\n", 2);
			return ;
		}
	}
}
