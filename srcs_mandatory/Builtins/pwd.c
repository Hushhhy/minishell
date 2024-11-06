/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:38:35 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/01 18:43:28 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_pwd(char *name, t_ms *ms)
{
	t_env	*cur;

	cur = ms->env;
	while (cur)
	{
		if (cur->name == name)
			return (cur->name);
		cur = cur->next;
	}
	return (NULL);
}

char	*get_cwd(t_ms *ms)
{
	char	*pwd;
	char	*cwd;

	pwd = get_env_pwd("PWD", ms);
	cwd = NULL;
	if (pwd == NULL || access(pwd, F_OK))
	{
		cwd = getcwd(NULL, 0);
		if (!cwd)
		{
			perror("getcwd");
			return (NULL);
		}
	}
	else
		cwd = strdup(pwd);
	return (cwd);
}

int	ft_pwd(t_ms *ms)
{
	char	*cwd;

	cwd = get_cwd(ms);
	if (!cwd)
		return (1);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	free(cwd);
	return (0);
}
