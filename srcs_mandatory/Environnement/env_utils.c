/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:24:52 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/18 18:09:04 by pgrellie         ###   ########.fr       */
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

// char	*transformed(char *var)
// {
// 	char	*new_var;
// 	int		len;
// 	int		x;

// 	x = 0;
// 	if (!var)
// 		return (NULL);
// 	len = strlen(var);
// 	new_var = malloc(sizeof(char) * (len + 3));
// 	if (!new_var)
// 		return (NULL);
// 	new_var[0] = '\"';
// 	while (x < len)
// 	{
// 		new_var[x + 1] = var[x];
// 		x++;
// 	}
// 	new_var[len + 1] = '\"';
// 	new_var[len + 2] = '\0';
// 	return (new_var);
// }