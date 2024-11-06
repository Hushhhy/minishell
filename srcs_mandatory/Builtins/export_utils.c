/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:34:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/06 15:00:27 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alr_exist(t_env *t_node, char *value, int equal_sign)
{
	if (value)
	{
		if (t_node->value)
			free(t_node->value);
		t_node->value = ft_strdup(value);
		if (!t_node->value)
			return ;
		free(value);
		value = NULL;
	}
	else if (!value && (equal_sign == 1
			|| t_node->equal_sign == 1))
	{
		if (t_node->equal_sign == 0)
			t_node->equal_sign = 1;
		if (t_node->value)
			free(t_node->value);
		t_node->value = NULL;
		if (!t_node->value)
			return ;
	}
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

char	*find_value(char *str)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	value = NULL;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (NULL);
	if (str[i] != '\0' && str[i + 1] != '\0')
	{
		i++;
		j = i;
		while (str[i])
			i++;
		value = ft_substr(str, j, i - j);
		if (!value)
			return (NULL);
	}
	return (value);
}
