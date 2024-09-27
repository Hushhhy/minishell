/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:13:11 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/26 15:13:11 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	print_export(t_env *env)
{
	no_args(env);
	while (env)
	{
		printf("export ");
		printf("%s", env->name);
		printf("=");
		if (env->value)
			printf("%s\n", env->value);
		else
			printf("\n");
	}
}

void	export_handle(t_env *env, t_token *tok)
{
	t_token	*value;

	if (value->value == ft_strchr(tok->value, "="))
		env->equal_sign = 1;
	else
		new_var(env, tok, 0);
}

void	ft_export(t_token *tok, t_env *env)
{
	t_env	*exist;
	char	*equal;
	char	*name;
	char	*value;
	t_env	*new;

	value = NULL;
	if (!tok->next)
		print_export(env);
	if (tok->type == ASSIGNMENT)
	{
		equal = ft_strchr(tok->value, '=');
		if (equal)
		{
			name = strndup(tok->value, equal - tok->value);
			value = ft_strdup(equal + 1);
		}
	}
	else
		name = ft_strdup(tok->value);
	exist = find_env(tok->value);
	if (exist)
		alr_exist(exist, value);
	else
		dont_exist(tok, new, name, value);
}
