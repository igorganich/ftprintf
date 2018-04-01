/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 03:06:15 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:07:45 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define RETURNER(p) return (p->wid_present? ft_max_of_two(p->wid, 1) : 1);

int	ft_printf(const char *format, ...);
#endif
