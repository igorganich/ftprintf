/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:32:59 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 04:33:01 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *temp;

	current = *alst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		ft_lstdelone(&temp, del);
	}
	*alst = NULL;
}
