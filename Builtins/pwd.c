/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:38:35 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/30 15:03:38 by acarpent         ###   ########.fr       */
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

void	ft_pwd()
{
	char	*cwd;

	cwd = get_cwd();
	if (!cwd)
		return ;
	printf("%s\n", cwd);
	free(cwd);
}
