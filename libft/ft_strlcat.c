/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:06:42 by iganich           #+#    #+#             */
/*   Updated: 2017/11/06 15:02:40 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t l;

	i = 0;
	l = -1;
	while (size - i != 0 && dst[i] != '\0')
		i++;
	if (size - i == 0)
	{
		while (src[++l] != '\0')
			;
		return (i + l);
	}
	while (src[++l] != '\0')
		if (i + l < size - 1)
			dst[i + l] = src[l];
		else if (i + l == size - 1)
			dst[i + l] = '\0';
	dst[i + l] = '\0';
	return (i + l);
}
