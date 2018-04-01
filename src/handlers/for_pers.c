/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_pers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:43:29 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:19:15 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/handle_funcs.h"
#include "../../libft/includes/libft.h"
#include "../../headers/utils.h"

ssize_t	ft_printf_func_pers(char **format, va_list *args, t_prs *parser)
{
	(void)format;
	(void)args;
	(void)parser;
	if (parser->wid_present && !parser->minus)
		ft_printf_func_wid_spec(1, parser->wid, parser->zero ? '0' : ' ');
	ft_putchar('%');
	if (parser->wid_present && parser->minus)
		ft_printf_func_wid_spec(1, parser->wid, ' ');
	RETURNER(parser);
}
