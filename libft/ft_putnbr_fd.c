/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:51:59 by iganich           #+#    #+#             */
/*   Updated: 2017/10/31 04:52:00 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getmodule(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

static void	gorecur(int n, int fd)
{
	if ((n / 10) != 0)
		gorecur(n / 10, fd);
	ft_putchar_fd(getmodule(n % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	gorecur(n, fd);
}
