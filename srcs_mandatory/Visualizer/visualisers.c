/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:23:10 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/25 17:00:16 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*get_token_type_name(t_token_type type)
{
	const char	*token_type_names[12];

	token_type_names[0] = "CMD";
	token_type_names[1] = "ARG";
	token_type_names[2] = "WORD";
	token_type_names[3] = "PIPE";
	token_type_names[4] = "INFILE";
	token_type_names[5] = "OUTFILE";
	token_type_names[6] = "REDIR_IN";
	token_type_names[7] = "REDIR_OUT";
	token_type_names[8] = "HERE_DOC";
	token_type_names[9] = "APPEND";
	token_type_names[10] = "LIMITER";
	if (type >= 0 && type < 11)
		return (token_type_names[type]);
	return ("UNKNOWN");
}

void	display_tokens(t_token *tokens)
{
	t_token	*token;

	token = tokens;
	while (token)
	{
		printf("Token: \033[0;36m %-20s \033[0m |\t \
			Type: \033[0;35m %-18s \033[0m \n",
			token->value, get_token_type_name(token->type));
		printf("--------------------------------------------------\n");
		token = token->next;
	}
}

void	display_envi(t_env *env)
{
	t_env	*envi;

	envi = env;
	while (envi)
	{
		printf("name: \033[0;36m %-20s \033[0m |\t \
			value: \033[0;35m %-18s \033[0m \n%d",
			envi->name, envi->value, envi->equal_sign);
		printf("--------------------------------------------------\n");
		envi = envi->next;
	}
}
