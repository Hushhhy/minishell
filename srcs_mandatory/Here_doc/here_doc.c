/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:55 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/16 14:40:02 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	papa_proces(pid_t pid, int pipefd[2])
{
	int	status;

	status = 0;
	close(pipefd[1]);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		return (1);
	close(pipefd[0]);
	return (0);
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
	while (1)
	{
		line = readline("> ");
		if (line_error(l, line, limiteur))
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

int	start_pipe(char *limiteur)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		is_working(pipefd, limiteur);
	else
	{
		signal(SIGINT, sigint_here_doc);
		signal(SIGQUIT, SIG_IGN);
		if (papa_proces(pid, pipefd))
			return (1);
	}
	return (0);
}

int	handle_here_doc(t_token *tok)
{
	here_doc_count(tok);
	while (tok)
	{
		if (parse_here_doc(tok))
			return (1);
		tok = tok->next;
	}
	return (0);
}
