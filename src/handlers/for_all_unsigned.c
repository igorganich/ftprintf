#include <stdint.h>
#include <sys/types.h>
#include "../../libft/includes/libft.h"
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"
#include <stdio.h>

static void	ft_putnbrbase_fd_inner(uintmax_t nbr, char *base, size_t baselen,
				int fd)
{
	if (nbr >= baselen)
	{
		ft_putnbrbase_fd_inner(nbr / baselen, base, baselen, fd);
		ft_putnbrbase_fd_inner(nbr % baselen, base, baselen, fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

static void	ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd)
{
	ft_putnbrbase_fd_inner(nbr, base, ft_strlen(base), fd);
}

static void	putnumber(uintmax_t number, char *base, t_prs *parser, unsigned *lens)
{
	if (parser->grid && ft_strlen(base) != 8)
		lens[0] += 2;
	if (parser->tochka_present)
		ft_printf_func_wid_spec(lens[0], parser->tochka, '0');
	if (number == 0 && parser->tochka_present && parser->tochka == 0)
		return ;
	else
		ft_putnbrbase_fd(number, base, STDOUT_FILENO);
	if (parser->grid && parser->tochka_present && ft_strlen(base) != 8)
		lens[1] -= 2;
}

static int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

ssize_t		ft_printf_func_uint(uintmax_t number,
		t_prs *parser, char *base, char *string)
{
	unsigned int	lens[2];

	if (parser->tochka_present)
		parser->zero = 0;
	lens[0] = ft_printf_get_len_nbr(number, base);
	if (parser->wid_present && !parser->minus && parser->zero)
	{
		if (parser->tochka_present)
			parser->tochka = maximum(parser->wid, parser->tochka);
		else
			parser->tochka = maximum(parser->wid, lens[0]);
		parser->tochka_present = 1;
		parser->wid_present = 0;
	}
	lens[1] = ft_printf_func_nbrlen_spec(number, base, string, parser);
	if (parser->wid_present && !parser->minus)
		ft_printf_func_wid_spec(lens[1], parser->wid, ' ');
	if (parser->grid && string != NULL && number != 0)
		ft_putstr(string);
	putnumber(number, base, parser, lens);
	if (parser->wid_present && parser->minus)
		ft_printf_func_wid_spec(lens[1], parser->wid, ' ');
	return (parser->wid_present ? (unsigned int)maximum(lens[1], parser->wid) : lens[1]);
}
