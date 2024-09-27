/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:53:35 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/27 15:06:38 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signals(void)
{
	char	*input;

	sigint_handler();
	sigquit_handler();
	while (1)
	{
		input = readline("minishell> ");
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		add_history(input);
		free(input);
	}
}
