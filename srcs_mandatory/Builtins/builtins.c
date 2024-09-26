/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:57 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/26 15:12:35 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtins(t_token *tok, t_env *env)
{
	if (ft_strcmp(tok->value, "echo") == 0)
		ft_echo(tok);
	else if (ft_strcmp(tok->value, "cd") == 0)
		ft_cd(tok);
	else if (ft_strcmp(tok->value, "exit") == 0)
		ft_exit(tok);
	else if (ft_strcmp(tok->value, "env") == 0)
		print_env(env);
	else if (ft_strcmp(tok->value, "pwd") == 0)
		ft_pwd(env);
	else if (ft_strcmp(tok->value, "unset") == 0)
		ft_unset(tok, env);
	else if (ft_strcmp(tok->value, "export") == 0)
		ft_export(tok, env);
}
