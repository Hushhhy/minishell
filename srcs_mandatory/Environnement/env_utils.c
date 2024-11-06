/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:24:52 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/05 14:49:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_equal_sign(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '=')
			return (x);
		x++;
	}
	return (-1);
}

t_env	*find_lastv(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
