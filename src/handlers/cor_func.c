#include "../../headers/handle_funcs.h"
#include "../../libft/includes/libft.h"

static void	create_funcs(t_func *handlers)
{
	handlers['%'] = &ft_printf_func_pers;
	handlers['s'] = &ft_printf_func_string;
	handlers['S'] = &ft_printf_func_wstring;
	handlers['p'] = &ft_printf_func_pointer;
	handlers['d'] = &ft_printf_func_int;
	handlers['D'] = &ft_printf_func_long;
	handlers['i'] = &ft_printf_func_int;
	handlers['o'] = &ft_printf_func_octal;
	handlers['O'] = &ft_printf_func_long;
	handlers['u'] = &ft_printf_func_unsigned;
	handlers['U'] = &ft_printf_func_long;
	handlers['x'] = &ft_printf_func_hex_small;
	handlers['X'] = &ft_printf_func_hex_big;
	handlers['c'] = &ft_printf_func_char;
	handlers['C'] = &ft_printf_func_wchar;
	handlers['b'] = &ft_printf_func_binary;
	handlers['f'] = &ft_printf_func_float;
	handlers['n'] = &ft_printf_func_charswritten;
}

t_func		ft_printf_get_func(char x, int flag)
{
	static t_func *funcs = NULL;
	t_func	buffer;

	ft_bzero(&buffer, sizeof(buffer));
	if (flag == 1)
	{
		if (funcs == NULL)
		{
			funcs = ft_memalloc(sizeof(*funcs) * (256));
			if (funcs != NULL)
				create_funcs(funcs);
		}
		return (funcs[(int)x]);
	}
	if (flag == 2)
	{
		free(funcs);
		funcs = NULL;
	}
	return (buffer);
}
