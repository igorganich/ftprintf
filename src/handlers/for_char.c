/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:41:27 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:19:49 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../libft/includes/libft.h"
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"

ssize_t	ft_printf_func_char(char **format, va_list *args, t_prs *parser)
{
	char c;

	(void)format;
	if (parser->len == key_l)
		return (ft_printf_func_wchar(format, args, parser));
	else
	{
		c = ' ';
		if (parser->zero)
			c = '0';
		if (parser->wid_present && !parser->minus)
			ft_printf_func_wid_spec(1, parser->wid, c);
		ft_putchar(va_arg(*args, int));
		if (parser->wid_present && parser->minus)
			ft_printf_func_wid_spec(1, parser->wid, ' ');
		RETURNER(parser);
	}
}
