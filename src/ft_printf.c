/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:30:29 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 02:32:53 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include "../headers/ft_printf.h"
#include "../headers/handle_funcs.h"
#include "../headers/parsers.h"
#include <unistd.h>

static int	handleit(char **format, va_list *args, t_prs *parser)
{
	int			count;
	t_func		myfunc;

	if ((*(++*format)) == '\0')
		return (0);
	ft_printf_check_special(format, parser);
	ft_printf_check_wid(format, args, parser);
	ft_printf_check_tochka(format, args, parser);
	ft_printf_check_len(format, parser);
	if (**format == '\0')
		return (0);
	myfunc = ft_printf_get_func(**format, 1);
	if (myfunc == NULL)
		myfunc = ft_printf_func_null;
	count = myfunc(format, args, parser);
	*format = *format + 1;
	return (count);
}

static int	goprint(const char *format, va_list *args, int count)
{
	char	*next;
	t_prs	parser;
	int		len;

	next = ft_strchr(format, '%');
	if (*format == '\0')
		return (count);
	if (next == NULL)
	{
		ft_putnstr_fd(format, ft_strlen(format), STDOUT_FILENO);
		return (count + ft_strlen(format));
	}
	else if (next > format)
	{
		ft_putnstr_fd(format, next - format, STDOUT_FILENO);
		return (goprint(next, args, count + (next - format)));
	}
	else
	{
		ft_bzero(&parser, sizeof(parser));
		if ((len = handleit((char**)&format, args, &parser)) == -1)
			return (-1);
		else
			return (goprint(format, args, count + len));
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	current_arg;
	int		count;

	va_start(current_arg, format);
	count = goprint(format, &current_arg, 0);
	va_end(current_arg);
	ft_printf_get_func('c', 2);
	return (count);
}
