/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:19:05 by codespace         #+#    #+#             */
/*   Updated: 2024/11/06 15:00:58 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_filename(void)
{
	char	*filename;

	filename = find_tmp_filename();
	if (filename == NULL)
		return (NULL);
	return (filename);
}

int	open_file(t_ms *ms, char *filename)
{
	ms->here_doc_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ms->here_doc_fd == -1)
	{
		free(filename);
		return (-1);
	}
	return (0);
}

char	*handle_null_line(t_ms *ms, char *filename, char *limiter)
{
	if (g_var == CTRL_C)
	{
		close(ms->here_doc_fd);
		unlink(filename);
		free(filename);
		return (NULL);
	}
	close(ms->here_doc_fd);
	eof_display(limiter);
	return (filename);
}

void	write_line_to_file(t_ms *ms, char *line)
{
	int	len;

	len = ft_strlen(line);
	write(ms->here_doc_fd, line, len);
	write(ms->here_doc_fd, "\n", 1);
}

int	check_line_against_limiter(char *line, char *limiter)
{
	if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
		&& (ft_strlen(line)) == ft_strlen(limiter))
	{
		free(line);
		return (1);
	}
	return (0);
}
