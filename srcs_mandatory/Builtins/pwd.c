/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:38:35 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/27 13:54:26 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cwd(void)
{
	char	*pwd;
	char	*cwd;

	pwd = getenv("PWD");
	cwd = NULL;
	if (pwd == NULL || access(pwd, F_OK) != 0)
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

void	ft_pwd(t_env *env)
{
	char	*cwd;

	cwd = get_cwd();
	if (!cwd)
		return ;
	printf("%s\n", cwd);
	free(cwd);
}

int	if_cd(const char *path)
{
	char	*new_cwd;

	if (chdir(path) != 0)
	{
		perror("chdir");
		return (1);
	}
	new_cwd = getcwd(NULL, 0);
	if (new_cwd)
	{
		setenv("PWD", new_cwd, 1);
		free(new_cwd);
	}
	else
	{
		perror("getcwd");
		return (1);
	}
	return (0);
}
