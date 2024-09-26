/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:23:31 by marvin            #+#    #+#             */
/*   Updated: 2024/09/25 11:23:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	changedir(const char *path)
{
	char *old;
	char *new;

	old = getenv("PWD");
	if (chdir(path) != 0)
		perror("cd");
	else
	{
		setenv("OLDPWD", old, 1);
		new = getcwd(NULL, 0);
		setenv("PWD", new, 1);
		free(new);
	}
}

void	cd(t_token *tok)
{
	if (tok)
		changedir(getenv("HOME"));
	if (tok->next)
	{
		if (ft_strcmp(tok->next, "-") == 0)
			changedir(getenv("OLDPWD"));
		else
			changedir(tok->next);
	}
	else
		printf("Too many arguments\n");
}