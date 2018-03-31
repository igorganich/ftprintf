#include <inttypes.h>
#include "../../libft/includes/libft.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"

static int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int	ft_printf_func_nbrlen_spec(uintmax_t number, char *base,
		char *p, t_prs *parser)
{
	unsigned int	len_of_nbr;
	unsigned int	len_of_str;

	len_of_nbr = ft_printf_get_len_nbr(number, base);
	if (number == 0 && parser->tochka_present && parser->tochka == 0)
		len_of_str = 0;
	else if (parser->tochka_present)
		len_of_str = maximum(len_of_nbr, parser->tochka);
	else
		len_of_str = len_of_nbr;
	if (parser->grid && p != NULL && number != 0)
		len_of_str = len_of_str + ft_strlen(p);
	return (len_of_str);
}
