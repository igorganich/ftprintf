/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:10:59 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 14:56:44 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	getmodule(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

static char	*reverse(char *first, int check)
{
	int		i;
	char	*second;
	int		l;

	second = ft_strnew(ft_strlen(first) + 1);
	if (second == NULL)
		return (second);
	i = -1;
	l = -1;
	if (check < 0)
		second[++l] = '-';
	if (check == 0)
	{
		second[0] = '0';
		return (second);
	}
	while (first[++i] != '\0')
		second[++l] = first[ft_strlen(first) - i - 1];
	return (second);
}

char		*ft_itoa(int n)
{
	char	*first;
	int		i;
	int		check;
	char	*second;

	check = n;
	i = -1;
	first = ft_strnew(12);
	if (first == NULL)
		return (NULL);
	while (n != 0)
	{
		first[++i] = getmodule(n % 10) + '0';
		n = n / 10;
	}
	second = reverse(first, check);
	return (second);
}
