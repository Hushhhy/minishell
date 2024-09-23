/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:23:29 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/18 18:29:24 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_envi(char *var)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
	{
		ft_putstr_fd("Error: failed to allocate memory for new env\n", 2);
		return (NULL);
	}
	new_env->value = getenv(var);
	new_env->name = ft_strdup(var);
	if (!new_env->value || !new_env->name)
	{
		free(new_env);
		ft_putstr_fd("Error: malloc failed\n", 2);
		return (NULL);
	}
	new_env->equal_sign = 1;
	new_env->next = NULL;
	new_env->prev = NULL;
	return (new_env);
}

void	add_env(t_env **env, char *var)
{
	t_env	*new_env;
	t_env	*last_env;

	if (env == NULL)
		return ;
	new_env = init_envi(var);
	if (!new_env)
		return ;
	if (*env == NULL)
	{
		*env = new_env;
		new_env->prev = NULL;
	}
	else
	{
		last_env = find_lastv(*env);
		last_env->next = new_env;
		new_env->prev = last_env;
	}
}

void	delete_env(t_env **head, t_env *node_to_del)
{
	if (*head == NULL || node_to_del == NULL)
		return ;
	if (*head == node_to_del)
		*head = node_to_del->next;
	if (node_to_del->next != NULL)
		node_to_del->next->prev = node_to_del->prev;
	if (node_to_del->prev != NULL)
		node_to_del->prev->next = node_to_del->next;
	free(node_to_del->value);
	free(node_to_del);
}

void	free_env(t_env **head)
{
	t_env	*current;
	t_env	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	*head = NULL;
}
