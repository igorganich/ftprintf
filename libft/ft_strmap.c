/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:41:55 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 15:09:03 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	i = -1;
	if (newstr)
		while (s[++i] != '\0')
			newstr[i] = f(s[i]);
	return (newstr);
}
