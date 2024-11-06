/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_list_redirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:26:09 by codespace         #+#    #+#             */
/*   Updated: 2024/11/01 16:52:53 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirs	*init_redirs_node(t_token *tok)
{
	t_redirs	*new_redirs;

	new_redirs = (t_redirs *)malloc(sizeof(t_redirs));
	if (!new_redirs)
	{
		ft_putstr_fd("Error: failed to allocate memory for new redirs\n", 2);
		return (NULL);
	}
	init_rs(new_redirs, tok);
	return (new_redirs);
}

void	add_redirs_node(t_redirs **redirs, t_token *tok)
{
	t_redirs	*new_redirs;
	t_redirs	*last_redirs;

	if (redirs == NULL || tok == NULL)
		return ;
	new_redirs = init_redirs_node(tok);
	if (!new_redirs)
		return ;
	if (*redirs == NULL)
	{
		*redirs = new_redirs;
		new_redirs->prev = NULL;
	}
	else
	{
		last_redirs = *redirs;
		while (last_redirs->next != NULL)
			last_redirs = last_redirs->next;
		last_redirs->next = new_redirs;
		new_redirs->prev = last_redirs;
	}
}

void	free_redirs_node(t_redirs *node)
{
	if (node->infile)
	{
		free(node->infile);
		node->infile = NULL;
	}
	if (node->outfile)
	{
		free(node->outfile);
		node->outfile = NULL;
	}
	free(node);
	node = NULL;
}

void	clear_redirs_list(t_redirs **redirs)
{
	t_redirs	*current;
	t_redirs	*next;

	if (redirs == NULL || *redirs == NULL)
		return ;
	current = *redirs;
	while (current != NULL)
	{
		next = current->next;
		free_redirs_node(current);
		current = next;
	}
	*redirs = NULL;
}
