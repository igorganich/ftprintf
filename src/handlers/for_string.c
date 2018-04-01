/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:57:04 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:00:21 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"
#include "../../libft/includes/libft.h"
#include <wchar.h>

static int		maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static size_t	custom_nstrlen(const char *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (*str++ && i < maxlen)
		i++;
	return (i);
}

ssize_t			ft_printf_func_string(char **format,
				va_list *args, t_prs *parser)
{
	int		len;
	char	*string;

	if (parser->len == key_l)
		return (ft_printf_func_wstring(format, args, parser));
	else
	{
		string = va_arg(*args, char*);
		if (string == NULL)
			string = "(null)";
		len = parser->tochka_present ? custom_nstrlen(string, parser->tochka) :
				ft_strlen(string);
		if (parser->wid_present && !parser->minus)
			ft_printf_func_wid_spec(len, parser->wid, parser->zero ?
					'0' : ' ');
		ft_putnstr_fd(string, len, STDOUT_FILENO);
		if (parser->wid_present && parser->minus)
			ft_printf_func_wid_spec(len, parser->wid, ' ');
		return (parser->wid_present ? maximum(len, parser->wid) : len);
	}
}
