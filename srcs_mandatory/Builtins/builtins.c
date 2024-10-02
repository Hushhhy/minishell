/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:57 by acarpent          #+#    #+#             */
/*   Updated: 2024/10/02 16:38:13 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins(t_ms *ms, t_token *tok)
{
	if (tok)
	{
		if (ft_strcmp(tok->value, "echo") == 0)
			ft_echo(tok);
		else if (ft_strcmp(tok->value, "cd") == 0)
			ft_cd(tok);
		else if (ft_strcmp(ms->tokens->value, "exit") == 0)
			ft_exit(ms->tokens);
		else if (ft_strcmp(ms->tokens->value, "env") == 0)
			print_env(tok, ms->env);
		else if (ft_strcmp(ms->tokens->value, "pwd") == 0)
			ft_pwd();
		else if (ft_strcmp(ms->tokens->value, "unset") == 0)
			ft_unset(ms->tokens, ms->env);
		else if (ft_strcmp(ms->tokens->value, "export") == 0)
			ft_export(ms);
	}
}
