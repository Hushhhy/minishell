/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:27:28 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/25 12:10:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_token *tok, t_env *env)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(tok->value);
	while (env)
	{
		if (ft_strncmp(env->name, tok->value, len) == 0 && env->equal_sign)
		{
			free(env);
			while (env)
			{
				env->name = env->next->name;
				env->value = env->next->value;
			}
			break ;
		}
		env = env->next;
	}
}