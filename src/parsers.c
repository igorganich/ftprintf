/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:33:18 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 02:39:48 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include "../headers/handle_funcs.h"

void		ft_printf_check_special(char **format, t_prs *parser)
{
	int flag;

	flag = 0;
	if (**format == 35 && (flag = 1))
		parser->grid = 1;
	else if (**format == 48 && (flag = 1))
		parser->zero = 1;
	else if (**format == '-' && (flag = 1))
		parser->minus = 1;
	else if (**format == 43 && (flag = 1))
		parser->plus = 1;
	else if (**format == 32 && (flag = 1))
		parser->space = 1;
	if (flag > 0)
		(*format)++;
	if (parser->minus && flag > 0)
		parser->zero = 0;
	if (flag > 0)
		ft_printf_check_special(format, parser);
}

static int	atoi_simple(char **format)
{
	int sum;

	sum = 0;
	while (ft_isdigit(**format))
		sum = (*(*format)++ - '0') + sum * 10;
	return (sum);
}

void		ft_printf_check_wid(char **format, va_list *list, t_prs *parser)
{
	int	fromarg;

	parser->wid = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			fromarg = va_arg(*list, int);
			if (fromarg < 0)
				parser->minus = 1;
			parser->wid = fromarg;
			if (fromarg < 0)
				parser->wid = -fromarg;
			parser->wid_present = 1;
		}
		if (ft_isdigit(**format))
		{
			parser->wid_present = 1;
			parser->wid = 0;
			parser->wid = atoi_simple(format);
		}
	}
}

void		ft_printf_check_tochka(char **format, va_list *list, t_prs *parser)
{
	int tochkavar;

	if (**format == 46)
	{
		(*format)++;
		if (**format == 42)
		{
			(*format)++;
			if ((tochkavar = va_arg(*list, int)) >= 0)
			{
				parser->tochka_present = 1;
				parser->tochka = tochkavar;
			}
			return (void)(*format);
		}
		else
		{
			parser->tochka_present = 1;
			parser->tochka = atoi_simple(format);
			return (void)(*format);
		}
	}
}

void		ft_printf_check_len(char **format, t_prs *parser)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		parser->len = key_hh;
		return ((void)(*format += 2));
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		parser->len = key_ll;
		return ((void)(*format += 2));
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' ||
					**format == 'z')
	{
		if (**format == 'h')
			parser->len = key_h;
		else if (**format == 'l')
			parser->len = key_l;
		else if (**format == 'j')
			parser->len = key_j;
		else if (**format == 'z')
			parser->len = key_z;
		return (void)((*format)++);
	}
}
