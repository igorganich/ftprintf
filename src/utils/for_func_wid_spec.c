/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_func_wid_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 03:03:01 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:03:30 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

void	ft_printf_func_wid_spec(int len, int wid, char c)
{
	while (len < wid)
	{
		ft_putchar(c);
		len++;
	}
}
