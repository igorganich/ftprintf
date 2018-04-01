/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:11:49 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:12:48 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	int				i;

	if (n == 0)
		return (0);
	i = n;
	u1 = (unsigned char*)s1;
	u2 = (unsigned char*)s2;
	while (--i > -1)
	{
		if (*u1 != *u2)
			return ((int)(*u1 - *u2));
		u1++;
		u2++;
	}
	return (0);
}
