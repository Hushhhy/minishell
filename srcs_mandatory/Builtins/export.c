/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:13:11 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/26 15:13:11 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	print_export(t_env *env)
{
	no_args(env);
	while (env)
	{
		printf("export ");
		printf("%s", env->name);
		if (env->equal_sign == 1)
			printf("=");
		if (env->value)
			printf("%s\n", env->value);
		else
			printf("\n");
		env = env->next;
	}
}

char	*find_name(t_token *tok, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (tok->value[i] && tok->value[i] != '=')
		i++;
	if (tok->value[i] == '=' || tok->value[i] == '\0')
		name = ft_substr(tok->value, j, i - j);
	return (name);
}

char	*find_value(t_token *tok, char *val)
{
	int	i;
	int	j;

	i = 0;
	while (tok->value[i] && tok->value[i] != '=')
		i++;
	if (tok->value[i] == '\0')
		return (NULL);
	if (tok->value[i] != '\0' && tok->value[i + 1] != '\0')
	{
		i++;
		j = i;
		while (tok->value[i])
			i++;
		val = ft_substr(tok->value, j, i - j);
	}
	return (val);
}

void	ft_export(t_ms *ms)
{
	t_env	*exist;
	char	*name;
	char	*value;
	t_env	*new;

	value = NULL;
	name = NULL;
	new = NULL;
	if (!ms->tokens->next)
		print_export(ms->env);
	else
	{
		ms->tokens = ms->tokens->next;
		while (ms->tokens)
		{
			name = find_name(ms->tokens, name);
			value = find_value(ms->tokens, value);
			exist = find_env(ms->env, name);
			if (exist)
				alr_exist(exist, value);
			else
				dont_exist(ms, new, name, value);
			ms->tokens = ms->tokens->next;
		}
	}
}
