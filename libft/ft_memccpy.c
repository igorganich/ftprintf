/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:40:35 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:41:16 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int ch, size_t num)
{
	size_t			i;
	unsigned char	*ndst;
	unsigned char	*nsrc;

	i = -1;
	ndst = (unsigned char*)dst;
	nsrc = (unsigned char*)src;
	while (++i < num)
	{
		ndst[i] = nsrc[i];
		if (ndst[i] == (unsigned char)ch)
			return ((void*)&(ndst[i + 1]));
	}
	return (NULL);
}
