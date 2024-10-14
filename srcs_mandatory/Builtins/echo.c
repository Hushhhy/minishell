/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:33:38 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/10 15:45:00 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_var(char *s)
{
	char	*var_s;
	char	*var_n;
	char	*env_val;

	if ((var_s = ft_strchr(s, '$')) != NULL)
	{
		var_n = var_s + 1;
		env_val = getenv(var_n);
		if (env_val)
		{
			*var_s = '\0';
			printf("%s%s", s, env_val);
		}
		else
			printf ("%s", s);
	}
	else
		printf("%s", s);
}

void	ft_echo(t_token *tok)
{
	int	nl;

	nl = 1;
	if (tok->next)
	{
		tok = tok->next;
		if (ft_strcmp(tok->value, "-n") == 0)
		{
			nl = 0;
			tok = tok->next;
		}
		while (tok && (ft_strcmp(tok->value, "|") != 0))
		{
			expand_var(tok->value);
			if (tok->next)
				printf(" ");
			tok = tok->next;
		}
		if (nl)
			printf("\n");
	}
	else
		printf("\n");
}
