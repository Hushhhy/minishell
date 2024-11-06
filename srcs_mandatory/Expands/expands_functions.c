/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:08:24 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/06 15:19:44 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*e_tracker(char *s)
{
	int		j;
	int		i;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = NULL;
	i = 0;
	if (s[i] == '$')
	{
		i++;
		j = i;
		while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
			i++;
		tmp = ft_substr(s, j, i - j);
		if (!tmp)
			return (NULL);
	}
	return (tmp);
}

void	maybe_del_node(t_token *tok, t_env *env)
{
	char	*e_name;
	t_env	*current;

	if (tok->value[0] == '$' && !tok->value[1])
		return ;
	if ((tok->value[0] == '$' && tok->value[1] == '?')
		|| (tok->value[0] == '$' && tok->value[1] == '$'))
		return ;
	e_name = e_tracker(tok->value);
	if (!e_name)
		return ;
	current = find_env(env, e_name);
	free(e_name);
	if (!current)
	{
		tok->to_del = true;
		return ;
	}
	else if (current && !current->value)
		tok->to_del = true;
	else if (current->value && ft_strcmp(current->value, "\"\"") == 0)
		tok->to_del = true;
	else
		return ;
}

void	double_dollar(char *fs, int *x, int *y)
{
	fs[(*y)++] = '$';
	fs[(*y)++] = '$';
	*x += 2;
}

void	dollar_bruh(char *fs, int *x, int *y, int v_return)
{
	char	*v_return_str;
	int		i;

	i = 0;
	v_return_str = ft_itoa(v_return);
	if (!v_return_str)
		return ;
	while (v_return_str[i])
	{
		fs[(*y)++] = v_return_str[i++];
	}
	free(v_return_str);
	*x += 2;
}

void	expand_variable(t_token *tok, t_env *env, t_var *v, char *fs)
{
	char	*var_name;
	t_env	*ev;
	char	*var_value;
	int		i;

	i = 0;
	var_name = tracker(tok->value, &v->x);
	if (!var_name)
		return ;
	ev = find_node(var_name, env);
	free(var_name);
	if (!ev || !ev->value)
		return ;
	var_value = ev->value;
	if (ev->value == NULL || ft_strcmp(ev->value, "\"\"") == 0)
		tok->to_del = true;
	while (var_value[i])
	{
		fs[v->y++] = var_value[i++];
	}
}
