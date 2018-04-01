/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:43:14 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 02:43:16 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/handle_funcs.h"
#include "../../headers/ft_printf.h"
#include "../../libft/includes/libft.h"

ssize_t	ft_printf_func_long(char **format, va_list *args, t_prs *parser)
{
	t_func function;

	parser->len = key_l;
	function = ft_printf_get_func(ft_tolower(**format), 1);
	return (function(format, args, parser));
}
