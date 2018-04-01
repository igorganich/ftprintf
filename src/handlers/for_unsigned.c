/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:43:56 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 02:43:58 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include <stddef.h>
#include "../../headers/utils.h"

ssize_t	ft_printf_func_unsigned(char **format, va_list *args, t_prs *parser)
{
	uintmax_t	number;

	(void)format;
	number = ft_printf_get_unsigned(args, parser);
	return (ft_printf_func_uint(number, parser, "0123456789", NULL));
}
