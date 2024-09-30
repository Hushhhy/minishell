/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:27:28 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/30 13:07:27 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_token *tok, t_env *env)
{
	int	i;
	int	len;

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
