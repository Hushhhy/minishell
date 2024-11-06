/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_chlist_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:53:36 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/01 17:22:17 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*init_token(char *value)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
	{
		ft_putstr_fd("Error: failed to allocate memory for new token", 2);
		return (NULL);
	}
	new_token->value = ft_strdup(value);
	if (!new_token->value)
	{
		free(new_token);
		ft_putstr_fd("Error: strdup failed", 2);
		return (NULL);
	}
	new_token->type = WORD;
	new_token->to_del = false;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

// Fonction pour ajouter un token à la liste chaînée
void	add_token(t_token **tok, char *value)
{
	t_token	*new_token;
	t_token	*last_token;

	if (tok == NULL)
		return ;
	new_token = init_token(value);
	if (!new_token)
		return ;
	if (*tok == NULL)
	{
		*tok = new_token;
		new_token->prev = NULL;
	}
	else
	{
		last_token = find_last(*tok);
		last_token->next = new_token;
		new_token->prev = last_token;
	}
}

void	delete_token(t_token **head, t_token *node_to_del)
{
	if (*head == NULL || node_to_del == NULL)
		return ;
	if (*head == node_to_del)
		*head = node_to_del->next;
	if (node_to_del->next != NULL)
		node_to_del->next->prev = node_to_del->prev;
	if (node_to_del->prev != NULL)
		node_to_del->prev->next = node_to_del->next;
	if (node_to_del->value)
	{
		free(node_to_del->value);
		node_to_del->value = NULL;
	}
	free(node_to_del);
	node_to_del = NULL;
}

void	free_tokens(t_token **head)
{
	t_token	*current;
	t_token	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		current->value = NULL;
		free(current);
		current = NULL;
		current = next;
	}
	*head = NULL;
}
