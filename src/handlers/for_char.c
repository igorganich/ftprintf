#include <stdarg.h>
#include "../../libft/includes/libft.h"
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"

ssize_t	ft_printf_func_char(char **format, va_list *args, t_prs *parser)
{
	char c;

	(void)format;
	if (parser->len == key_l)
		return (ft_printf_func_wchar(format, args, parser));
	else
	{
		c = ' ';
		if (parser->zero)
			c = '0';
		if (parser->wid_present && !parser->minus)
			ft_printf_func_wid_spec(1, parser->wid, c);
		ft_putchar(va_arg(*args, int));
		if (parser->wid_present && parser->minus)
			ft_printf_func_wid_spec(1, parser->wid, ' ');
		returner(parser);//make returner in header
	}
}
