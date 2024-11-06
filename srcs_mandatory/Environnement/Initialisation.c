/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:52:47 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/06 15:20:05 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	add_env_var(t_env **envi, char *env_var)
{
	char	*var;
	int		x;

	x = find_equal_sign(env_var);
	if (x > 0)
	{
		var = ft_substr(env_var, 0, x);
		if (!var)
		{
			ft_putstr_fd("malloc failed", 2);
			return (false);
		}
		add_env(envi, var);
		free(var);
	}
	return (true);
}

t_env	*init_env(char **env)
{
	t_env	*envi;
	int		j;

	envi = NULL;
	j = 0;
	if (env == NULL)
		return (NULL);
	while (env[j])
	{
		if (!add_env_var(&envi, env[j]))
			return (NULL);
		j++;
	}
	return (envi);
}

/*	ctrl X
	ctrl A
	pour gdb */