/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:29:28 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/31 18:42:25 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_ms	*ms;

	if (ac == 1)
	{
		(void)av;
		ms = init_program(env);
		the_program(ms);
		free(ms);
	}
	else
		ft_putstr_fd("Arguments aren't allowed\n", 2);
	return (0);
}
