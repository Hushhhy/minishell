/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:34:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/26 16:38:09 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    swap_list(t_env *a, t_env *b)
{
    t_env *tmp;

    tmp = a;
    a = b;
    b = tmp;
}

int	no_args(t_env *env)
{
	int sorted;

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
