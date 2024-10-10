/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:53:35 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/30 16:23:10 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signals(void)
{
	char	*input;
	int		sig_val;

	sig_val = SIGINT;
	ft_sigint_handler(sig_val);
	ft_sigquit_handler(sig_val);
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
