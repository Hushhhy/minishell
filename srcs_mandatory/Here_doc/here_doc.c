/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:33:18 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/02 18:25:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	papa_proces(pid_t pid)
{
	char	*buffer;
	int		bytes;
	int		pipefd[2];

	buffer = NULL;
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
	while ((bytes = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes] = '\0';
		ft_putstr_fd(buffer, 1);
	}
	close(pipefd[0]);
}

void	read_until_limit(char *limiteur)
{
	char	*line;
	int		pipefd[2];
	int		sig_val;

	sig_val = SIGINT;
	while (1)
	{
		line = readline("> ");
		ft_sigint_setup();
		if (!line || ft_strcmp(line, limiteur) == 0)
		{
			free(line);
			break;
		}
		free(line);
	}
	close(pipefd[1]);
	exit(0);
}

void	start_pipe(char *limiteur)
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
	{
		close(pipefd[0]);
		read_until_limit(limiteur);
	}
	else
		papa_proces(pid);
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
			start_pipe(tok->next->value);
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
