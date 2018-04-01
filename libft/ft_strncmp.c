/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:28:24 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:28:27 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *p1, const char *p2, size_t size)
{
	size_t i;

	i = 0;
	while (p1[i] != '\0' && p1[i] == p2[i] && i < size - 1)
		i++;
	if (!size)
		return (0);
	return ((unsigned char)(p1[i]) - (unsigned char)(p2[i]));
}
