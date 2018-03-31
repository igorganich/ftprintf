#include "../../libft/includes/libft.h"
#include <stdlib.h>
#include "../../headers/utils.h"

ssize_t	ft_printf_numberandstring(uintmax_t number,
		char *base, t_prs *parser, char *string)
{
	unsigned	len;
	size_t		cut;

	cut = ft_strlen(string);
	len = ft_printf_func_nbrlen_spec(number, base, NULL, parser) +
		cut;
	if (parser->wid_present && !parser->minus && !parser->zero)
	{
		ft_printf_func_wid_spec(len, parser->wid, ' ');
		if (parser->wid - len > 0)
			cut = cut + parser->wid - len;
		parser->wid_present = 0;
	}
	else if (parser->wid_present)
		parser->wid -= ft_strlen(string);
	ft_putstr(string);
	return (ft_printf_func_uint(number, parser, base, NULL) + cut);
}
