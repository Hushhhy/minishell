/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:55 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/04 16:54:10 by acarpent         ###   ########.fr       */
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
	while (1)
	{
		line = readline("> ");
		if (line_error(l, line, limiteur) == false)
			break;
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



















// int	tmp_file(int fd)
// {
// 	fd = open("/tmp/heredoc_tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 	}
// 	return (fd);
// }

// void	is_here_doc(t_token *tok)
// {
// 	if (tok)
// 	{
// 		if (tok->type == HERE_DOC && !tok->next)
// 		{
// 			ft_putstr_fd("minishell: ", 2);
// 			ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
// 			return ;
// 		}
// 		if (tok->type == HERE_DOC && tok->next->type == LIMITER)
// 			handle_here_doc(tok->next->value);
// 		else if (tok->type == HERE_DOC && tok->next->type != LIMITER)
// 		{
// 			ft_putstr_fd("minishell: ", 2);
// 			ft_putstr_fd("syntax error near unexpected token '", 2);
// 			ft_putstr_fd(tok->next->value, 2);
// 			ft_putstr_fd("'\n", 2);
// 			return ;
// 		}
// 	}
// }

// void	here_doc_launch(int fd, char *limiter, char *line, int l)
// {
// 	fd = tmp_file(fd);
// 	fprintf(stderr, "fd is: %d\n", fd);
// 	rl_outstream = stderr;
// 	while (1)
// 	{
// 		line = readline("> ");
// 		if (line_error(l, line, limiter) == false)
// 			break ;
// 		if (ft_strcmp(line, limiter) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		// ft_putstr_fd(line, fd);
// 		// ft_putstr_fd("\n", fd);
// 		l++;
// 		free(line);
// 	}
// 	close(fd);
// 	exit(0);
// }

// void	kid_wait(int pid, int status, int fd)
// {
// 	int backup = dup(STDIN_FILENO);
// 	waitpid(pid, &status, 0);
// 	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
// 	{
// 		fd = open("/tmp/heredoc_tmp.txt", O_RDONLY);
// 		if (fd == -1)
// 		{
// 			perror("open");
// 			exit(EXIT_FAILURE);
// 		}
// 		dup2(fd, STDIN_FILENO);
// 		close(fd);
// 		unlink("/tmp/heredoc_tmp.txt");
// 	}
// 	else if (WIFSIGNALED(status))
// 		printf("Here_doc interrupted\n");
// }

// void	handle_here_doc(char *limiter)
// {
// 	char	*line;
// 	int		l;
// 	int		fd;
// 	pid_t	pid;
// 	int		status;

// 	fd = 0;
// 	l = 1;
// 	status = 0;
// 	line = NULL;
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid == 0)
// 	{
// 		signal(SIGINT, SIG_DFL);
// 		signal(SIGQUIT, SIG_IGN);
// 		// here_doc_sigint_setup();
// 		// ft_sigquit_setup();
// 		here_doc_launch(fd, limiter, line, l);
// 	}
// 	else
// 	{
// 		signal(SIGQUIT, SIG_IGN);
// 		signal(SIGINT, SIG_IGN);
// 		kid_wait(pid, status, fd);
// 	}
	
// }
