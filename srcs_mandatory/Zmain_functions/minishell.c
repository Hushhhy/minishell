/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:29:28 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/11 16:14:01 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	static t_ms	*ms;

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

	// printf("Helo");
	// return (0);

	// acceper uniquement les '|' et '<' et '>' et '<<' et '>>'

	// faire deux listes chaines : une pour les tokens
	// et une autres pour les expands