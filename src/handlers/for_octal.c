/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:56:05 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:20:09 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"
#include <stdlib.h>
#include "../../libft/includes/libft.h"

static int	ft_printf_maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

ssize_t		ft_printf_func_octal(char **format, va_list *args, t_prs *parser)
{
	uintmax_t	number;

	(void)format;
	number = ft_printf_get_unsigned(args, parser);
	if (parser->grid && number == 0 &&
				parser->tochka_present && parser->tochka == 0)
	{
		if (parser->wid_present && !parser->minus)
			ft_printf_func_wid_spec(1, parser->wid, parser->zero ? '0' : ' ');
		ft_putnstr_fd("0", 1, STDOUT_FILENO);
		if (parser->wid_present && parser->minus)
			ft_printf_func_wid_spec(1, parser->wid, ' ');
		RETURNER(parser);
	}
	else if (parser->grid && number != 0)
	{
		parser->tochka_present = 1;
		parser->tochka = ft_printf_maximum(parser->tochka,
		ft_printf_get_len_nbr(number, "01234567") + 1);
	}
	return (ft_printf_func_uint(number, parser, "01234567", NULL));
}
