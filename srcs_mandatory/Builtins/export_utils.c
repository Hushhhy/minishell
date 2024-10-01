/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:34:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/01 15:32:39 by acarpent         ###   ########.fr       */
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

void	swap_list(t_env *cur, t_env *next)
{
	char	*tmpn;
	char	*tmpv;
	int		tmpe;

	tmpn = cur->name;
	tmpv = cur->value;
	tmpe = cur->equal_sign;
	cur->name = next->name;
	cur->value = next->value;
	cur->equal_sign = next->equal_sign;
	next->name = tmpn;
	next->value = tmpv;
	next->equal_sign = tmpe;
}

void	no_args(t_env *env)
{
	int		sorted;
	t_env	*lptr;
	t_env	*ptr;

	if (env == NULL)
		return ;
	sorted = 1;
	lptr = NULL;
	while (sorted)
	{
		sorted = 0;
		ptr = env;
		while (ptr && ptr->next != lptr)
		{
			if (ft_strcmp(ptr->name, ptr->next->name) > 0)
			{
				swap_list(ptr, ptr->next);
				sorted = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
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
