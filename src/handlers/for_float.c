#include "../../headers/handle_funcs.h"
#include "../../libft/includes/libft.h"
#include "../../headers/utils.h"
#include <stdarg.h>

ssize_t	ft_printf_func_float(char **format, va_list *args, t_prs *parser)
{
	float	floating;

	(void)format;
	(void)parser;
	floating = (float)va_arg(*args, double);
	(void)floating;
	ft_putstr("Float");
	return (0);
}
