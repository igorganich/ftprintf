/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:21:00 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 12:53:45 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	int		n;
	char	*ndst;
	char	*nsrc;

	n = num;
	ndst = (char*)dst;
	nsrc = (char*)src;
	while (--n > -1)
	{
		ndst[n] = nsrc[n];
	}
	return (dst);
}
