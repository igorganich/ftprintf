#include <stdarg.h>
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include <stddef.h>
#include "../../headers/utils.h"

ssize_t	ft_printf_func_unsigned(char **format, va_list *args, t_prs *parser)
{
	uintmax_t	number;

	(void)format;
	number = ft_printf_get_unsigned(args, parser);
	return (ft_printf_func_uint(number, parser, "0123456789", NULL));
}
