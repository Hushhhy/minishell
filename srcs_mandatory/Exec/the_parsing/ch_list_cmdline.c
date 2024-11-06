/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ch_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:12:16 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/11 16:44:59 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*init_cmdline_node(void)
{
	t_cmdline	*new_node;

	new_node = (t_cmdline *)malloc(sizeof(t_cmdline));
	if (!new_node)
	{
		ft_putstr_fd("Error: failed to allocate memory", 2);
		return (NULL);
	}
	new_node->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_node->cmd)
	{
		free(new_node);
		ft_putstr_fd("Error: failed to allocate memory for cmd", 2);
		return (NULL);
	}
	init_cmd(new_node);
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_cmdline_node(t_cmdline **cmdline, t_token *tok)
{
	t_cmdline	*new_node;
	t_cmdline	*last_node;

	if (cmdline == NULL || tok == NULL)
		return ;
	new_node = init_cmdline_node();
	if (!new_node)
		return ;
	new_node->cmd->tok = tok;
	new_node->cmd->cmds = the_cmds(tok);
	new_node->cmd->redirs = the_redirs(tok);
	if (*cmdline == NULL)
	{
		*cmdline = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = *cmdline;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	delete_cmdline_node(t_cmdline **head, t_cmdline *node_to_del)
{
	if (*head == NULL || node_to_del == NULL)
		return ;
	if (*head == node_to_del)
		*head = node_to_del->next;
	if (node_to_del->next != NULL)
		node_to_del->next->prev = node_to_del->prev;
	if (node_to_del->prev != NULL)
		node_to_del->prev->next = node_to_del->next;
	clear_redirs_list(&node_to_del->cmd->redirs);
	free(node_to_del->cmd);
	node_to_del->cmd = NULL;
	free(node_to_del);
	node_to_del = NULL;
}

void	clear_cmdlines(t_cmdline **head)
{
	t_cmdline	*current;
	t_cmdline	*next;

	current = *head;
	while (current->prev)
		current = current->prev;
	while (current)
	{
		next = current->next;
		clear_redirs_list(&current->cmd->redirs);
		ft_free_tab(current->cmd->cmds);
		free(current->cmd);
		current->cmd = NULL;
		free(current);
		current = NULL;
		current = next;
	}
	*head = NULL;
}
