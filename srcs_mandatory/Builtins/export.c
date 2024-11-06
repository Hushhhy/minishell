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

void	init_export(t_export *export)
{
	export->name = NULL;
	export->value = NULL;
	export->new = NULL;
}

void	print_export(t_env *env)
{
	no_args(env);
	while (env)
	{
		ft_putstr_fd("export ", 1);
		ft_putstr_fd(env->name, 1);
		if (env->equal_sign == 1)
			ft_putstr_fd("=", 1);
		if (env->equal_sign == 1)
		{
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
}

char	*find_name(char *str, int *equal_sign)
{
	char	*name;
	int		i;
	int		j;

	i = 0;
	j = i;
	name = NULL;
	if (str[0] == '=')
		return (export_error(str));
	while (str[i] && str[i] != '=')
	{
		if ((!ft_isalpha(str[i]) && str[i] != '_')
			|| ft_isdigit(str[0]))
			return (export_error(str));
		i++;
	}
	if (str[i] == '=')
		*equal_sign = 1;
	if (str[i] == '=' || str[i] == '\0')
	{
		name = ft_substr(str, j, i - j);
		if (!name)
			return (NULL);
	}
	return (name);
}

int	ft_export(t_ms *ms)
{
	t_export	exp;
	int			i;
	int			equal_sign;

	i = 0;
	equal_sign = 0;
	init_export(&exp);
	if (!ms->cmdlines->cmd->cmds[1])
		print_export(ms->env);
	else
	{
		i++;
		while (ms->cmdlines->cmd->cmds[i])
		{
			if (process_export(ms, &exp, ms->cmdlines->cmd->cmds[i],
					&equal_sign))
				return (1);
			i++;
		}
	}
	return (0);
}
