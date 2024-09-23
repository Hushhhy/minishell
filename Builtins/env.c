/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:57:06 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/23 15:07:23 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_env(t_env *env)
{
    while (env)
    {
        printf("%s", env->name);
        if (env->equal_sign == 1)
            printf("=");
        if (env->value)
            printf("%s\n", env->value);
        env = env->next;
    }
}