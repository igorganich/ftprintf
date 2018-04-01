/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:26:01 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 04:26:12 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *buf;
	char *last;

	last = NULL;
	buf = (char*)str;
	while (*buf != '\0')
	{
		if (*buf == ch)
			last = buf;
		buf++;
	}
	if (*buf == ch)
		last = buf;
	return (last);
}
