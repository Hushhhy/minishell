/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:33:38 by acarpent          #+#    #+#             */
/*   Updated: 2024/09/30 16:52:30 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_token *tok)
{
	int	nl;

	nl = 1;
	if (tok->next)
	{
		tok = tok->next;
		if (ft_strcmp(tok->value, "-n") == 0)
		{
			nl = 0;
			tok = tok->next;
		}
		while (tok)
		{
			printf("%s", tok->value);
			if (tok->next)
				printf(" ");
			tok = tok->next;
		}
		if (nl)
			printf("\n");
	}
	else
		printf("\n");
}
