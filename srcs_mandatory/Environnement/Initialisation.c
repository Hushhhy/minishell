/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:52:47 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/24 17:40:50 by pgrellie         ###   ########.fr       */
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
			printf("malloc failed");
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
	// display_envi(envi);
	return (envi);
}

/*	ctrl X
	ctrl A
	pour gdb */