/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:07:37 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:07:42 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t num)
{
	size_t i;
	size_t l;

	l = 0;
	i = -1;
	while (dest[++i] != '\0')
		;
	while (l < num && src[l] != '\0')
	{
		dest[i + l] = src[l];
		l++;
	}
	dest[i + l] = '\0';
	return (dest);
}
