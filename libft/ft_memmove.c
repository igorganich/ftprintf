/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:32:32 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 13:11:44 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	char	*cdst;
	char	*csrc;
	int		i;
	int		size;

	size = num;
	i = -1;
	cdst = (char*)dst;
	csrc = (char*)src;
	if (csrc > cdst)
		while (++i < size)
			cdst[i] = csrc[i];
	else
	{
		i = num;
		while (--i > -1)
			cdst[i] = csrc[i];
	}
	return (cdst);
}
