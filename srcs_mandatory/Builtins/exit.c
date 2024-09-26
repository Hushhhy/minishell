/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:23:52 by marvin            #+#    #+#             */
/*   Updated: 2024/09/25 11:23:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_num(const char *str)
{
	int i;

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

void	exit(t_token *tok)
{
	int exit_stat;

	exit_stat = 0;
	if (!tok->next)
		exit(exit_stat);
	if (!is_num(tok->next))
	{
		printf("exit: %s: numeric argument needed\n", tok->next);
		exit(255);
	}
	tok = tok->next;
	if (tok->next)
	{
		printf("exit: too many arguments\n");
		return ;
	}
	exit_stat = ft_atoi(tok->value);
	exit(exit_stat);
}