/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:38:14 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/30 15:14:45 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	handle_dollar_dollar(int *x)
{
	*x += 2;
	return (2);
}

static size_t	handle_dollar_question(int v_return, int *x)
{
	char	*v_ret;
	int		len;

	*x += 2;
	v_ret = ft_itoa(v_return);
	len = ft_strlen(v_ret);
	free(v_ret);
	return (len);
}

static size_t	handle_env_variable(char *value, int *x, t_env *env)
{
	char	*tmp;
	t_env	*ev;
	size_t	len;

	len = 0;
	tmp = tracker(value, x);
	if (!tmp)
		return (0);
	ev = find_node(tmp, env);
	free(tmp);
	if (!ev || !ev->value)
		return (0);
	if (ev->value)
		len = ft_strlen(ev->value);
	return (len);
}

static size_t	handle_other_chars(int *x)
{
	(*x)++;
	return (1);
}

char	*malloc_calculator(t_token *tok, t_env *env, int v_return)
{
	size_t	len;
	int		x;

	x = 0;
	len = 0;
	while (tok->value[x])
	{
		if (tok->value[x + 1] && tok->value[x] == '$'
			&& tok->value[x + 1] == '$')
			len += handle_dollar_dollar(&x);
		else if (tok->value[x + 1] && tok->value[x] == '$'
			&& tok->value[x + 1] == '?' && expandable(tok->value, x))
			len += handle_dollar_question(v_return, &x);
		else if (tok->value[x] == '$' && expandable(tok->value, x)
			&& tok->value[x + 1])
			len += handle_env_variable(tok->value, &x, env);
		else
			len += handle_other_chars(&x);
	}
	return ((char *)ft_calloc(len + 1, sizeof(char)));
}

/*********************************************************************/

// char	*malloc_calculator(t_token *tok, t_env *env, int v_return)
// {
// 	size_t	len;
// 	int		x;
// 	char	*tmp;
// 	t_env	*ev;

// 	x = 0;
// 	len = 0;
// 	tmp = NULL;
// 	while (tok->value[x])
// 	{
// 		if (tok->value[x] == '$' && tok->value[x + 1] == '$')
// 		{
// 			x += 2;
// 			len += 2;
// 		}
// 		else if (tok->value[x] == '$' && tok->value[x + 1] == '?'
// 			&& expandable(tok->value, x))
// 		{
// 			x += 2;
// 			len += ft_strlen(ft_itoa(v_return));
// 		}
// 		else if (tok->value[x] == '$' && expandable(tok->value, x)
// 			&& tok->value[x + 1])
// 		{
// 			tmp = tracker(tok->value, &x);
// 			ev = find_node(tmp, env);
// 			len += ft_strlen(ev->value);
// 			free(tmp);
// 		}
// 		else
// 		{
// 			len ++;
// 			x++;
// 		}
// 	}
// 	return ((char *)ft_calloc(1, sizeof(char) * len + 2));
// }