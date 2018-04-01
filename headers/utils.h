/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 03:08:11 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:08:58 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <inttypes.h>
# include "handle_funcs.h"

uintmax_t		ft_printf_get_unsigned(va_list *args, t_prs *parser);
void			ft_printf_func_wid_spec(int nbrstrlen, int width, char padwith);
unsigned int	ft_printf_get_len_nbr(uintmax_t nbr, char *base);
unsigned int	ft_printf_func_nbrlen_spec(uintmax_t number
		, char *base, char *p, t_prs *parser);
ssize_t			ft_printf_numberandstring(uintmax_t number
		, char *base, t_prs *parser, char *string);
#endif
