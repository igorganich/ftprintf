/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:16:05 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 15:30:20 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = -1;
	string = ft_strnew(len);
	if (string)
		while (++i < len)
			string[i] = s[start++];
	return (string);
}
