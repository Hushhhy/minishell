/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:12:57 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/26 15:12:57 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_token *tok)
{
	int	exit_stat;

	exit_stat = 0;
	if (!tok->next)
	{
		printf("exit\n");
		exit(exit_stat);
	}
	if (!is_num(tok->next->value))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(tok->next->value, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	tok = tok->next;
	if (tok->next)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return ;
	}
	exit_stat = ft_atoi(tok->value);
	exit(exit_stat);
}
