/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:05:08 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:05:10 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *current;

	newlst = NULL;
	if (lst != NULL)
	{
		newlst = f(lst);
		current = newlst;
		lst = lst->next;
	}
	while (lst != NULL)
	{
		current->next = f(lst);
		if (current->next == NULL)
			return (NULL);
		current = current->next;
		lst = lst->next;
	}
	return (newlst);
}
