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
	}
}

void	token_decompose(t_token *tok, char *name, char *value)
{
	int	i;
	int	j;
	int	equal;

	i = 0;
	j = i;
	equal = 0;
	while (tok->value[i] && tok->value[i] != '=')
		i++;
	if (tok->value[i] == '=' || tok->value[i] == '\0')
	{
		name = ft_substr(tok->value, j, i - j);
		if (tok->value[i] == '=')
			equal = 1;
	}
	if (tok->value[i] != '\0' && tok->value[i + 1] != '\0')
	{
		i++;
		j = i;
		while (tok->value[i])
			i++;
		value = ft_substr(tok->value, j, i - j);
	}
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
	while (ms->tokens)
	{
		token_decompose(ms->tokens, name, value);
		exist = find_env(ms->env, name);
		if (exist)
			alr_exist(exist, value);
		else
			dont_exist(ms, new, name, value);
		ms->tokens = ms->tokens->next;
	}
}
