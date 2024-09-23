/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs_N_return_values_manager.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:43:24 by pgrellie          #+#    #+#             */
/*   Updated: 2024/08/27 18:44:02 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_error(bool mf)
{
	if (mf == false)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'", 2);
		return (2);
	}
	else
		return (0);
}
