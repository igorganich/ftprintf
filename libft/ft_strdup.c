/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:31:25 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 14:07:38 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		i;

	i = -1;
	temp = NULL;
	while (src[++i] != '\0')
		;
	temp = (char*)malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (NULL);
	temp[i] = '\0';
	while (--i > -1)
		temp[i] = src[i];
	return (temp);
}
