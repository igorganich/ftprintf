/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freenode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:24:33 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:18:35 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		freenode(t_list **first, t_list *node)
{
	t_list *current;

	if (*first == node)
	{
		node = node->next;
		free((*first)->secondstr);
		free(*first);
		*first = node;
		return (0);
	}
	current = *first;
	while (current->next != node)
		current = current->next;
	current->next = current->next->next;
	free(node->secondstr);
	free(node);
	return (0);
}
