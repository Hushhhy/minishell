/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:35:23 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/02 17:01:42 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_separator(char *s, int *x, t_token **tok)
{
	int	i;

	i = *x;
	if ((s[*x] == '<' && s[*x + 1] == '<')
		|| (s[*x] == '>' && s[*x + 1] == '>'))
		*x += 2;
	else
		*x += 1;
	add_token(tok, ft_substr(s, i, *x - i));
}

// Fonction pour gérer les mots

void	handle_word(char *s, int *x, t_token **tok)
{
	int		i;
	char	quote;
	bool	in_quotes;
	char	*tmp;

	i = *x;
	in_quotes = false;
	while (s[*x] && !is_space(s[*x])
		&& (in_quotes || !is_separator(s[*x], s[*x + 1])))
	{
		if (is_quote(s[*x]))
		{
			quote = s[*x];
			in_quotes = !in_quotes;
			*x += 1;
			while (s[*x] && s[*x] != quote)
				*x += 1;
			if (s[*x] == quote)
				in_quotes = !in_quotes;
		}
		*x += 1;
	}
	tmp = ft_substr(s, i, *x - i);
	add_token(tok, tmp);
	free(tmp);
}

void	butcher(char *s, t_token **tok)
{
	int		x;

	x = 0;
	while (is_space(s[x]))
		x++;
	while (s[x])
	{
		if (is_quote(s[x]))
			handle_word(s, &x, tok);
		else if (!is_space(s[x]) && is_separator(s[x], s[x + 1])
			&& is_quoted(s, x) == false)
			handle_separator(s, &x, tok);
		else if (!is_space(s[x]) && !is_separator(s[x], s[x + 1]))
			handle_word(s, &x, tok);
		else
			x++;
	}
}

void	assign_token_types(t_token *tokens)
{
	while (tokens)
	{
		tokens->type = da_tok(tokens->value, tokens->prev);
		tokens = tokens->next;
	}
}

t_token	*lexer(char *input)
{
	t_token	*tokens;

	tokens = NULL;
	if (input == NULL)
		return (NULL);
	butcher(input, &tokens);
	assign_token_types(tokens);
	display_tokens(tokens);
	return (tokens);
}
