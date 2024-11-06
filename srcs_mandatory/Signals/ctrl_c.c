/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:46:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/06 15:11:35 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint_hd(int sig)
{
	(void)sig;
	g_var = CTRL_C;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_sigint(int sig)
{
	(void)sig;
	g_var = CTRL_C;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	child_sigint(int sig)
{
	(void)sig;
	g_var = CTRL_C;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}
