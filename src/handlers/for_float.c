/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 02:53:28 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 02:54:25 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/handle_funcs.h"
#include "../../libft/includes/libft.h"
#include "../../headers/utils.h"
#include <stdarg.h>
#include <unistd.h>

ssize_t	ft_printf_func_float(char **format, va_list *args, t_prs *parser)
{
	float	floating;

	(void)format;
	(void)parser;
	floating = (float)va_arg(*args, double);
	(void)floating;
	ft_putnstr_fd("Float", 5, STDOUT_FILENO);
	return (0);
}
