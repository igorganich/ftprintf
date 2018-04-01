/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 03:15:00 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:15:01 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

void	ft_putnstr_fd(char const *str, size_t str_len, int fd)
{
	ssize_t first;

	first = write(fd, str, str_len);
	first = first - 1;
}
