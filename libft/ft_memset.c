/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:29:28 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:31:47 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = -1;
	str = (unsigned char*)memptr;
	while (++i < n)
		str[i] = c;
	return (memptr);
}
