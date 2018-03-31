#include "../../headers/handle_funcs.h"
#include "../../headers/ft_printf.h"
#include "../../libft/includes/libft.h"
#include "../../headers/utils.h"

ssize_t	ft_printf_func_null(char **format, va_list *args, t_prs *parser)
{
	(void)args;
	if (parser->wid_present)
		if (!parser->minus)
			ft_printf_func_wid_spec(1, parser->wid, parser->zero ? '0' : ' ');
	ft_putchar(**format);
	if (parser->wid_present && parser->minus)
		ft_printf_func_wid_spec(1, parser->wid, ' ');
	returner(parser);
}
