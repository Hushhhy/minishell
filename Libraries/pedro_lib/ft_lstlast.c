/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:31:44 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/17 15:35:59 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

t_list	*ft_lstlast(t_list *blst)
{
	t_list	*tmp;

	if (!blst)
		return (NULL);
	tmp = blst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
