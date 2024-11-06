/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:28:01 by codespace         #+#    #+#             */
/*   Updated: 2024/11/06 15:00:44 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_file_opener(t_ms *ms, int *last_fd_in, t_redirs *redir)
{
	_maybe_fd_closing(*last_fd_in);
	if (access(redir->infile, F_OK) != 0)
	{
		perror(redir->infile);
		clean_child(ms);
		exit(1);
	}
	*last_fd_in = open(redir->infile, O_RDONLY);
	if (*last_fd_in < 0)
	{
		perror(redir->infile);
		clean_child(ms);
		exit(1);
	}
	redirect_and_close(*last_fd_in, STDIN_FILENO);
}

void	outfile_opener(t_ms *ms, int *last_fd_out, t_redirs *redir)
{
	_maybe_fd_closing(*last_fd_out);
	if (redir->out_flag == true)
		*last_fd_out = open(redir->outfile,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->out_app == true)
		*last_fd_out = open(redir->outfile,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*last_fd_out < 0)
	{
		perror(redir->outfile);
		clean_child(ms);
		exit(1);
	}
	redirect_and_close(*last_fd_out, STDOUT_FILENO);
}

void	ft_open_files(t_ms *ms)
{	
	int			last_fd_out;
	int			last_fd_in;
	t_redirs	*current;

	last_fd_in = -1;
	last_fd_out = -1;
	current = ms->cmdlines->cmd->redirs;
	while (current)
	{
		if (current->out_flag == true || current->out_app == true)
			outfile_opener(ms, &last_fd_out, current);
		else if (current->in_flag == true || current->hd_flag == true)
			in_file_opener(ms, &last_fd_in, current);
		current = current->next;
	}
}
