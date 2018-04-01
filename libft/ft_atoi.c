/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:21:31 by iganich           #+#    #+#             */
/*   Updated: 2017/11/04 14:38:28 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsign(const char *str, int *signi)
{
	int i;

	*signi = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 18)
		*signi = -1;
	if (str[0] == '-' && i > 18)
		*signi = 0;
	return (*signi);
}

int			ft_atoi(const char *str)
{
	int sum;
	int sign;

	sum = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (getsign(str, &sign) != 1)
		return (sign);
	if (*str == '-' || *str == '+')
		if (*(++str - 1) == '-')
			sign = -1;
	if (*str > '9' || *str < '0')
		return (0);
	while (*str <= '9' && *str >= '0')
		sum = sum * 10 + (*(str++) - '0');
	return (sum * sign);
}
