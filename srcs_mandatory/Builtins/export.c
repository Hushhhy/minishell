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

void	new_var(t_env *env, t_token *tok, int equal)
{

}

void	export_handle(t_env *env, t_token *tok)
{
	t_token *value;
	if (value->value = ft_strchr(tok->value, "="))
	{
		env->equal_sign = 1;
	}
	else
		new_var(env, tok, 0);
}

void	ft_export(t_token *tok, t_env *env)
{
	int i;

	if (!tok->next)
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
	i = 1;
	while (tok->value[i])
	{
		
	}
}
