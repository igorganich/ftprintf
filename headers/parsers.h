/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 03:08:00 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:08:01 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H
# include "handle_funcs.h"

char	*ft_printf_check_special(char **format, t_prs *parser);
char	*ft_printf_check_wid(char **format, va_list *list, t_prs *parser);
char	*ft_printf_check_tochka(char **format, va_list *list, t_prs *parser);
char	*ft_printf_check_len(char **format, t_prs *parser);
#endif
