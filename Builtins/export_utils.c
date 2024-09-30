/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:34:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/30 15:03:14 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alr_exist(t_env *exist, char *value)
{
	if (value)
	{
		free(exist->value);
		exist->value = value;
	}
	exist->equal_sign = (value != NULL);
}

void	dont_exist(t_ms *ms, t_env *new, char *name, char *value)
{
	new = (t_env *)malloc(sizeof(t_env));
	new->name = name;
	new->value = value;
	new->equal_sign = (value != NULL);
	new->next = ms->env->next;
	new->prev = NULL;
	if (ms->env)
		ms->env->prev = new;
	ms->env = new;
}

void	swap_list(t_env *a, t_env *b)
{
	t_env	*tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	no_args(t_env *env)
{
	int	sorted;

	if (env == NULL)
		return ;
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		while (env != NULL && env->next != NULL)
		{
			if (ft_strcmp(env->name, env->next->name) > 0)
			{
				swap_list(env, env->next);
				sorted = 0;
			}
			env = env->next;
		}
	}
}

t_env	*find_env(t_env *env, const char *find)
{
	while (env)
	{
		if (ft_strcmp(env->name, find) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}
