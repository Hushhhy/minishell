/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:57:06 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/01 13:47:32 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_token *tok, t_env *env)
{
	if (tok->next)
	{
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
		return ;
	}
	while (env)
	{
		if (env->equal_sign == 1)
		{
			printf("%s", env->name);
			printf("=");
		}
		if (env->value)
			printf("%s\n", env->value);
		else
			printf("\n");
		env = env->next;
	}
}
