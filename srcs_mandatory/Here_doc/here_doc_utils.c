/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:02:46 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/16 13:21:57 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arg_not_found(char *s)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	syntax_error(t_token *tok)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token '", 2);
	ft_putstr_fd(tok->next->value, 2);
	ft_putstr_fd("'\n", 2);
}

void	is_working(int pipefd[2], char *limiteur)
{
	close(pipefd[0]);
	read_until_limit(limiteur, pipefd[1]);
}
