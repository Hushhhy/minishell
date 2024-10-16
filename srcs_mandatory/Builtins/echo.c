/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:33:38 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/16 15:32:22 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	only_n(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' && s[1] == 'n')
		i += 2;
	while (s[i])
	{
		if (s[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

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
			ft_putstr_fd(s, 1);
			ft_putstr_fd(env_val, 1);
		}
		else
			ft_putstr_fd(s, 1);
	}
	else
		ft_putstr_fd(s, 1);
}

void	ft_echo(t_token *tok)
{
	int	nl;

	nl = 1;
	if (tok->next)
	{
		tok = tok->next;
		if (only_n(tok->value))
		{
			nl = 0;
			tok = tok->next;
		}
		while (tok && (ft_strcmp(tok->value, "|") != 0))
		{
			expand_var(tok->value);
			if (tok->next)
				ft_putstr_fd(" ", 1);
			tok = tok->next;
		}
		if (nl)
			ft_putstr_fd("\n", 1);
	}
	else
		ft_putstr_fd("\n", 1);
}
