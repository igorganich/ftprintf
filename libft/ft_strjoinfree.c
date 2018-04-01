/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:14:40 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:14:22 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(t_list *s1, char *s2)
{
	char *string;
	char *string2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string = ft_strnew((size_t)(ft_strlen((char*)s1->content)) +
		(size_t)(ft_strlen((char*)s2)) + 1);
	if (string == NULL)
		return (NULL);
	string2 = ft_strcat(ft_strcat(string, s1->content), s2);
	free(s1->secondstr);
	s1->secondstr = string2;
	return (string2);
}
