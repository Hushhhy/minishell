/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:12:43 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/26 15:12:43 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	changedir(char *path)
{
	char		*new;

	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		new = getcwd(NULL, 0);
		setenv("PWD", new, 1);
		free(new);
	}
}

void	ft_cd(t_token *tok)
{
	if (!tok->next)
		changedir(getenv("HOME"));
	else if (tok->next)
	{
		tok = tok->next;
		if (tok->next)
			ft_putstr_fd("minishel: cd: too many arguments\n", 2);
		else
			changedir(tok->value);
	}
	else
		ft_putstr_fd("minishell: cd: usage: cd <path>\n", 2);
}
