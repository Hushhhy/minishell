/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:27:28 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/01 16:21:24 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_node(t_env *env, t_env *delete)
{
	delete = env;
	if (delete)
	{
		if (env->prev)
			env->prev->next = env->next;
		if (env->next)
			env->next->prev = env->prev;
		free(env->name);
		free(env->value);
		free(env);
	}
}

void	ft_unset(t_token *tok, t_env *env)
{
	int		i;
	t_env	*delete;

	i = 0;
	delete = NULL;
	if (tok->next)
	{
		tok = tok->next;
		while (env)
		{
			if (ft_strcmp(env->name, tok->value) == 0)
			{
				del_node(env, delete);
				break ;
			}
			env = env->next;
		}
	}
}
