/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:08:38 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:08:45 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlist;

	nlist = malloc(sizeof(t_list));
	if (nlist)
	{
		if (!content)
			nlist->content = NULL;
		if (!content)
			nlist->content_size = 0;
		if (content)
		{
			nlist->content = ft_memalloc(content_size);
			ft_memcpy(nlist->content, content, content_size);
			nlist->secondstr = (char*)nlist->content;
			nlist->content_size = content_size;
		}
		nlist->next = NULL;
	}
	return (nlist);
}
