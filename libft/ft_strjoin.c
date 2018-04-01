/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:14:40 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 15:40:49 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *string;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string = ft_strnew((size_t)(ft_strlen((char*)s1)) +
		(size_t)(ft_strlen((char*)s2)) + 1);
	if (string == NULL)
		return (NULL);
	return (ft_strcat(ft_strcat(string, s1), s2));
}
