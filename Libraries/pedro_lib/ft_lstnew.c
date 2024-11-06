/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:55:49 by pgrellie          #+#    #+#             */
/*   Updated: 2024/08/29 15:55:09 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nem;

	nem = malloc(sizeof(t_list));
	if (!nem)
		return (free(nem), NULL);
	nem->content = content;
	nem->next = NULL;
	return (nem);
}
