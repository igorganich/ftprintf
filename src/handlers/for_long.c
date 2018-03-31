#include "../../headers/handle_funcs.h"
#include "../../headers/ft_printf.h"
#include "../../libft/includes/libft.h"

ssize_t	ft_printf_func_long(char **format, va_list *args, t_prs *parser)
{
	t_func function;

	parser->len = key_l;
	function = ft_printf_get_func(ft_tolower(**format), 1);
	return (function(format, args, parser));
}
