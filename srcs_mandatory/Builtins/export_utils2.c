/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:59:34 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/06 15:15:43 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*export_error(char *str)
{
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (NULL);
}

t_env	*init_exp_node(char *name, char *value, int equal_sign)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
	{
		ft_putstr_fd("Error: failed to allocate memory for new env\n", 2);
		return (NULL);
	}
	new_env->equal_sign = equal_sign;
	new_env->name = ft_strdup(name);
	if (!new_env->name)
		return (NULL);
	if (value)
	{
		new_env->value = ft_strdup(value);
		if (!new_env->value)
			return (NULL);
	}
	else
	new_env->value = NULL;
	new_env->next = NULL;
	new_env->prev = NULL;
	return (new_env);
}

void	add_new(t_env **env, char *name, char *value, int equal_sign)
{
	t_env	*new_env;
	t_env	*last_env;

	if (env == NULL)
		return ;
	new_env = init_exp_node(name, value, equal_sign);
	if (!new_env)
		return ;
	free(name);
	name = NULL;
	if (value)
		free(value);
	if (*env == NULL)
	{
		*env = new_env;
		new_env->prev = NULL;
	}
	else
	{
		last_env = find_lastv(*env);
		last_env->next = new_env;
		new_env->prev = last_env;
	}
}

int	process_export(t_ms *ms, t_export *exp, char *cmd, int *equal_sign)
{
	exp->name = find_name(cmd, equal_sign);
	if (!exp->name)
		return (1);
	exp->value = find_value(cmd);
	exp->t_node = find_env(ms->env, exp->name);
	if (exp->t_node)
	{
		free(exp->name);
		alr_exist(exp->t_node, exp->value, *equal_sign);
	}
	else
		add_new(&ms->env, exp->name, exp->value, *equal_sign);
	return (0);
}
