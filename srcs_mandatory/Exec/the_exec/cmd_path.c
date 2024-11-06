/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:32:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/01 15:19:55 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_directory(char *path, t_ms *ms)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		closedir(dir);
		ft_putstr_fd("MYSHELL : Is a directory\n", 2);
		free(path);
		clean_child(ms);
		exit(126);
	}
}

void	check_executable(char *path, t_ms *ms)
{
	if (access(path, X_OK) != 0)
	{
		ft_putstr_fd("MYSHELL : Permission denied\n", 2);
		free(path);
		clean_child(ms);
		exit(126);
	}
}

char	*handle_direct_path(char *cmd, t_ms *ms)
{
	char	*path;

	if (ft_strchr(cmd, '/'))
	{
		path = ft_strdup(cmd);
		if (access(path, F_OK) == 0)
		{
			check_directory(path, ms);
			check_executable(path, ms);
		}
		else if (access(path, F_OK) != 0)
		{
			ft_putstr_fd("MYSHELL : No such file or directory\n", 2);
			free(path);
			clean_child(ms);
			exit(127);
		}
		return (path);
	}
	return (NULL);
}

char	*search_in_path(char **envi, char *cmd)
{
	int		x;
	char	*path;
	char	**pathsss;

	x = 0;
	while (envi[x])
	{
		if (ft_strncmp(envi[x], "PATH=", 5) == 0)
		{
			path = ft_strdup(envi[x] + 5);
			pathsss = ft_split(path, ':');
			free(path);
			path = env_for_exec(pathsss, cmd);
			if (path)
				return (path);
		}
		x++;
	}
	return (NULL);
}

char	*cmd_path(char **envi, char *cmd, t_ms *ms)
{
	char	*path;

	if (!cmd)
		return (NULL);
	path = handle_direct_path(cmd, ms);
	if (path)
		return (path);
	else
		return (search_in_path(envi, cmd));
}
