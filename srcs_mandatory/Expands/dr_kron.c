/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_kron.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:02:28 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/27 20:18:00 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(char *str)
{
	size_t	i;
	size_t	j;
	bool	in_single_quote;
	bool	in_double_quote;

	i = 0;
	j = 0;
	in_single_quote = false;
	in_double_quote = false;
	while (str[i])
	{
		if (str[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (str[i] == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void	finishing(t_token *tok)
{
	while (tok)
	{
		remove_quotes(tok->value);
		tok = tok->next;
	}
}

char	*process_token_value(t_token *tok,
				t_env *env, int v_return, char *fs)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (tok->value[x])
	{
		if (tok->value[x] == '$' && tok->value[x + 1] == '$')
		{
			fs = double_dollar(fs);
			x = ft_strlen(fs);
		}
		else if (tok->value[x] == '$' && tok->value[x + 1] == '?'
			&& expandable(tok->value, x))
			fs = dollar_bruh(fs, &x, v_return);
		else if (tok->value[x] == '$' && expandable(tok->value, x))
			fs = expand_variable(tok, env, &x, fs);
		else
			fs[y++] = tok->value[x++];
		if (!fs)
			return (NULL);
		y = ft_strlen(fs);
	}
	fs[y] = '\0';
	return (fs);
}

char	*transformer(t_token *tok, char *fs)
{
	if (!tok || !fs)
		return (NULL);
	// printf("Debug: old token value: %s\n", tok->value);
	// printf("Debug: new value: %s\n", fs);
	if (tok->value)
		free(tok->value);
	tok->value = strdup(fs);
	if (!tok->value)
		return (NULL);
	free(fs);
	// printf("Debug: updated token value: %s\n", tok->value);
	return (tok->value);
}

void	dr_kron(t_token *tok, t_env *env, int v_return)
{
	char	*fs;

	if (!tok || !env || !tok->value || !env->value)
		return ;
	fs = process_token_value(tok, env, v_return, fs);
	if (!fs)
		return ;
	transformer(tok, fs);
}
