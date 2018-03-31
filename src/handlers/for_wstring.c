#include <stdarg.h>
#include "../../libft/includes/libft.h"
#include "../../headers/ft_printf.h"
#include "../../headers/handle_funcs.h"
#include "../../headers/utils.h"

static int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}



static size_t	get_len(wchar_t *string, int tochka, size_t count)
{
	if (*string == '\0' || tochka == 0)
		return (count);
	else if (*string <= 127)
		return (get_len(string + 1, tochka - 1, count + 1));
	else if (*string <= 2047 && tochka >= 2)
		return (get_len(string + 1, tochka - 2, count + 2));
	else if (*string <= 65535 && tochka >= 3)
		return (get_len(string + 1, tochka - 3, count + 3));
	else if (*string <= 1114111 && tochka >= 4)
		return (get_len(string + 1, tochka - 4, count + 4));
	else
		return (count);
}

static size_t	ft_wstrlen(wchar_t *str)
{
	size_t	count;
	size_t	l;

	count = 0;
	l = -1;
	while (str[++l])
	{
		if (str[l] <= 127)
			count++;
		else if (str[l] <= 2047)
			count += 2;
		else if (str[l] <= 65535)
			count += 3;
		else if (str[l] <= 1114111)
			count += 4;
	}
	return (count);
}

ssize_t			ft_printf_func_wstring(char **format, va_list *args, t_prs *parser)
{
	size_t	len;
	wchar_t	*string;

	(void)format;
	(void)parser;
	string = va_arg(*args, wchar_t*);
	if (string == NULL)
		string = L"(null)";
	len = parser->tochka_present ? get_len(string, parser->tochka, 0) :
			ft_wstrlen(string);
	if (parser->wid_present && !parser->minus)
		ft_printf_func_wid_spec(len, parser->wid, parser->zero ? '0' : ' ');
	ft_putnwstr(string, len);
	if (parser->wid_present && parser->minus)
		ft_printf_func_wid_spec(len, parser->wid, ' ');
	return (parser->wid_present ? (size_t)maximum(len, parser->wid) : len);
}
