/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:39:53 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 05:41:43 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *buf;

	buf = (char*)str;
	while (*buf != '\0')
		if (*buf == ch)
			return (buf);
		else
			buf++;
	if (ch == '\0')
		return (buf);
	return (NULL);
}
