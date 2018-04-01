/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:47:45 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 14:50:53 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_resplit(char **splitter, char *s, char *first, int size)
{
	char	**temp;
	int		i;

	i = -1;
	temp = (char**)malloc(sizeof(char*) * size + 1);
	if (temp)
	{
		while (++i < size - 1)
			temp[i] = splitter[i];
		i = -1;
		temp[size - 1] = ft_strnew((size_t)(first - s) + 1);
		temp[size] = NULL;
		while (s != first)
			temp[size - 1][++i] = *(s++);
	}
	free(splitter);
	return (temp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*first;
	char	**splitter;
	int		size;

	size = 0;
	splitter = (char**)malloc(sizeof(char**) * 1);
	if (splitter == NULL)
		return (NULL);
	splitter[0] = NULL;
	if (s)
		while (*s != '\0')
		{
			while (*s == c && *s != '\0')
				s++;
			first = (char*)s;
			while (*first != c && *first != '\0')
				first++;
			if (*first != '\0' || first[-1] != c)
				splitter = ft_resplit(splitter, (char*)s, first, ++size);
			if (!splitter)
				return (NULL);
			s = first;
		}
	return (splitter);
}
