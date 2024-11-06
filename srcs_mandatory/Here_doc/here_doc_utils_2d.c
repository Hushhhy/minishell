/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:18:59 by codespace         #+#    #+#             */
/*   Updated: 2024/11/01 16:14:43 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_tmp_files(void)
{
	int		x;
	char	*tmp_itoa;
	char	*filename;

	x = 1;
	while (1)
	{
		tmp_itoa = ft_itoa(x);
		filename = ft_strjoin("/tmp/.here_doc", tmp_itoa);
		if (access(filename, F_OK) == -1)
		{
			free(tmp_itoa);
			free(filename);
			break ;
		}
		unlink(filename);
		free(tmp_itoa);
		free(filename);
		x++;
	}
}

char	*find_tmp_filename(void)
{
	char	*filename;
	int		x;
	char	*tmp_itoa;

	x = 1;
	while (1)
	{
		tmp_itoa = ft_itoa(x);
		filename = ft_strjoin("/tmp/.here_doc", tmp_itoa);
		free(tmp_itoa);
		if (filename == NULL)
			return (NULL);
		if (access(filename, F_OK) == -1)
			return (filename);
		free(filename);
		x++;
	}
}

void	eof_display(char *limiter)
{
	ft_putstr_fd("MYSHELL: warning: ", 2);
	ft_putstr_fd("here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(limiter, 2);
	ft_putstr_fd("')\n", 2);
}

void	here_doc_count(t_ms *ms, t_token *tok)
{
	t_token	*here;
	int		x;

	here = tok;
	x = 1;
	while (here)
	{
		if (here->type == HERE_DOC)
		{
			if (x == 17)
			{
				ft_putstr_fd("minishell: maximum here-document ", 2);
				ft_putstr_fd("count exceeded\n", 2);
				clear_program_hd(ms);
				exit(2);
			}
			x++;
		}
		here = here->next;
	}
}

void	close_all_fds(void)
{
	int	x;

	x = 3;
	while (x < 1024)
	{
		close(x);
		x++;
	}
}
