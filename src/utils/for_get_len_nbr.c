/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_get_len_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 03:04:02 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:04:22 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/types.h>
#include "../../libft/includes/libft.h"

unsigned int	ft_printf_get_len_nbr(uintmax_t number, char *base)
{
	size_t			size;
	unsigned int	i;

	size = ft_strlen(base);
	i = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= size;
		i++;
	}
	return (i);
}
