/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:50:22 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 04:23:28 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "../../libft/includes/libft.h"
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"
#include <unistd.h>
#include <stdio.h>//asdasdads

static void	ft_putwchar_fd(wchar_t chr, int fd)
{
	ft_printf(" number is %d\n", (int)(chr));
	if (chr <= 0x7F)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF)
	{
		ft_putchar_fd((chr >> 6) + 0xC0, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_fd((chr >> 12) + 0xE0, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar_fd((chr >> 18) + 0xF0, fd);
		ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
}

static int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

ssize_t		ft_printf_func_wchar(char **format, va_list *args, t_prs *parser)
{
	wchar_t		charact;
	unsigned	charactlen;

	(void)format;
	charact = (wchar_t)va_arg(*args, wint_t);
	if (charact <= 0x7F)
		charactlen = 1;
	else if (charact <= 0x7FF)
		charactlen = 2;
	else if (charact <= 0xFFFF)
		charactlen = 3;
	else if (charact <= 0x10FFFF)
		charactlen = 4;
	else
		charactlen = 0;
	if (parser->wid_present && !parser->minus)
		ft_printf_func_wid_spec(charactlen, parser->wid,
				parser->zero ? '0' : ' ');
	ft_putwchar_fd(charact, STDOUT_FILENO);
	if (parser->wid_present && parser->minus)
		ft_printf_func_wid_spec(charactlen, parser->wid,
				parser->zero ? '0' : ' ');
	return (parser->wid_present ? (unsigned)maximum(charactlen
			, parser->wid) : charactlen);
}
