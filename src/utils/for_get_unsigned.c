#include <stdint.h>
#include <sys/types.h>
#include <stdarg.h>
#include "../../headers/handle_funcs.h"

uintmax_t	ft_printf_get_unsigned(va_list *args, t_prs *parser)
{
	uintmax_t	number;

	number = va_arg(*args, uintmax_t);
	if (parser->len == key_hh)
		number = (unsigned char)number;
	else if (parser->len == key_h)
		number = (unsigned short int)number;
	else if (parser->len == key_l)
		number = (unsigned long int)number;
	else if (parser->len == key_ll)
		number = (unsigned long long int)number;
	else if (parser->len == key_j)
		number = (uintmax_t)number;
	else if (parser->len == key_z)
		number = (size_t)number;
	else
		number = (unsigned int)number;
	return (number);
}
