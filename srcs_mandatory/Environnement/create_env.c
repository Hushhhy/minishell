/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:46:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/06 15:00:14 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_create(char *name, char *value)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
	{
		ft_putstr_fd("Error: failed to allocate memory for new env\n", 2);
		return (NULL);
	}
	new_env->value = ft_strdup(value);
	new_env->name = ft_strdup(name);
	if (!new_env->value || !new_env->name)
	{
		if (new_env->name)
			free(new_env->name);
		if (new_env->value)
			free(new_env->value);
		free(new_env);
		ft_putstr_fd("Error: malloc failed\n", 2);
		return (NULL);
	}
	if (value)
		new_env->equal_sign = 1;
	new_env->next = NULL;
	new_env->prev = NULL;
	return (new_env);
}

void	add_create(t_env **env, char *name, char *value)
{
	t_env	*new_env;
	t_env	*last_env;

	if (!name || !value)
		return ;
	last_env = NULL;
	new_env = init_create(name, value);
	if (!new_env)
		return ;
	if (*env == NULL)
	{
		*env = new_env;
		new_env->prev = NULL;
	}
	else
	{
		while (new_env->next)
			new_env = new_env->next;
		last_env = new_env;
		new_env->prev = last_env;
	}
}

t_env	*create_env(void)
{
	t_env	*envi;
	char	*cwd;

	envi = NULL;
	cwd = getcwd(NULL, 0);
	add_create(&envi, "PWD", cwd);
	free(cwd);
	return (envi);
}
