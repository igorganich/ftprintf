/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:17:54 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:24:56 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int val, size_t num)
{
	unsigned char	*str;
	size_t			i;

	i = -1;
	str = (unsigned char*)src;
	while (++i < num)
	{
		if (str[i] == (unsigned char)val)
			return ((void*)str + i);
	}
	return (0);
}
