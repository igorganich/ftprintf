/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:54:39 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 05:17:37 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../libft/includes/libft.h"
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"
#include <stdint.h>

static intmax_t	ft_printf_get_signed(va_list *args, t_prs *parser)
{
	intmax_t	number;

	number = va_arg(*args, intmax_t);
	if (parser->len == key_hh)
		number = (char)number;
	else if (parser->len == key_h)
		number = (short int)number;
	else if (parser->len == key_l)
		number = (long int)number;
	else if (parser->len == key_ll)
		number = (long long int)number;
	else if (parser->len == key_j)
		number = (intmax_t)number;
	else if (parser->len == key_z)
		number = (size_t)number;
	else
		number = (int)number;
	return (number);
}

ssize_t			ft_printf_func_int(char **format, va_list *args, t_prs *parser)
{
	intmax_t				number;
	char					*string;

	(void)format;
	if (parser->tochka_present)
		parser->zero = 0;
	number = ft_printf_get_signed(args, parser);
	if (number < 0 || parser->plus || parser->space)
	{
		if (number < 0)
		{
			number *= -1;
			string = "-";
		}
		else if (parser->plus)
			string = "+";
		else if (parser->space)
			string = " ";
		else
			string = "";
		return (ft_printf_numberandstring(number, "0123456789",
					parser, string));
	}
	else
		return (ft_printf_func_uint(number, parser, "0123456789", NULL));
}
