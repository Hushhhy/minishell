/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:08:24 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/23 13:29:34 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*find_node(char *s, t_env *env)
{
	while (env)
	{
		if (strcmp(s, env->name) == 0)
		{
			return (env);
		}
		env = env->next;
	}
	return (NULL);
}

char	*tracker(t_token *tok)
{
	int		x;
	int		j;
	char	*tmp;

	x = 0;
	while (tok->value[x])
	{
		if (tok->value[x] == '$' && tok->value[x + 1] == '$')
			return (NULL);
		if (ft_strchr(tok->value[x], '$'))
		{
			x++;
			j = x;
			while (!is_space(tok->value[x]) && tok->value[x] != '$')
				x++;
			tmp = ft_substr(tok->value, j, x - j);
			if (!tmp)
			{
				ft_putstr_fd("Error: malloc failed mother fucker", 2);
				return (NULL);
			}
		}
	}
	return (tmp);
}

t_token	*dr_kron(t_token *tok, t_env *env)
{
	t_token	*toks;
	int		x;
	char	*fs;
	char	*tmp;

	x = 0;
	fs = malloc(sizeof(char) * malloc_calculator(tok, env));
	if (!fs)
		return (NULL);
	while (tok->value[x])
	{
		if (tok->value[x] == '$')
		{
			fs = ft_strjoin(tmp, env->value);
		}
		tmp = ft_copy(tok);
		x++;
	}
	free(tmp);
	return (toks);
}

t_token	*expander(t_ms *ms)
{
	t_token	*tok;
	t_env	*env;
	char	*tmp;

	while (ms->tokens)
	{
		if (ms->tokens->type == WORD || ms->tokens->type == INFILE
			|| ms->tokens->type == OUTFILE || ms->tokens->type == EXPAND
			|| (ms->tokens->type == CMD && ms->tokens->prev == NULL))
		{
			tmp = tracker(ms->tokens);
			tok = ms->tokens;
			env = find_node(tmp, ms->env);
			if (env)
				tok = dr_kron(ms->tokens, env);
			free(tmp);
		}
		ms->tokens = ms->tokens->next;
	}
	return (tok);
}

// Entre double quote -> remplacement

// Entre single quote -> pas de remplacement

// $EXPAND doit etre suivi d'un espace pour etre remplace

// $$ -> NULL

// Malloc la nouvelle chaine moins les quotes

// $? -> renvoi la valeur de retour (A gerer a part des variables d'environnement)
