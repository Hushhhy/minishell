/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:44:59 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/08 13:57:18 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	full_check(char *s)
{
	if (q_check(s) == false || c_check(s) == false
		|| shit_check_1(s) == false)
	{
		ft_putstr_fd("/! error bitch /! \n", 2);
		return (false);
	}
	else
		return (true);
}
