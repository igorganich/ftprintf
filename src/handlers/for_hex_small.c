#include <stdarg.h>
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"

ssize_t ft_printf_func_hex_small(char **format, va_list *args, t_prs *parser)
{
	uintmax_t	number;
	char		first;
	ssize_t		size;

	first = **format;
	first = first + 1;
	number = ft_printf_get_unsigned(args, parser);
	size = ft_printf_func_uint(number, parser, "0123456789abcdef", "0x");
	return (size);
}
