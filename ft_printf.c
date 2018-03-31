#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "parse_handlers.h"
#include <stdio.h>//aasd

static int	handleit(char **format, va_list *args, t_prs *parser)
{
	int		count;
	t_func		myfunc;

	printf("here\n");
	if ((*(++*format)) == '\0')
		return (0);
	ft_printf_check_special(format, parser);
	ft_printf_check_width(format, args, parser);
	ft_printf_check_tochka(format, args, parser);
	ft_printf_check_len(format, parser);
	if (**format == '\0')
		return (0);
	printf("your d is%d\n", **format);
	myfunc = ft_printf_get_func(**format);
	if (myfunc == NULL)
		myfunc = ft_printf_func_null;
	count = func(format, args, sarg);
	(*format)++;
	return (count);
}

static int			goprint(const char *format, va_list *args, int count)
{
	char	*next;
	t_prs	parser;
	int	len;

	next = ft_strchr(format, '%');
	if (*format == '\0')
		return (count);
	if (next == NULL)
	{
		ft_putstr(format);
		return (count + ft_strlen(format));
	}
	else if (next > format)
	{
		ft_putnstr(format, next - format);
		return (goprint(next, args, count + (next - format)));
	}
	else
	{
		ft_bzero(&parser, sizeof(parser));
		if ((len = handleit((char**)&format, args, &parser)) == -1)
			return (-1);
		else
			return (goprint(format, args, count + len));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	current_arg;
	int	count;

	va_start(current_arg, format);
	count = goprint(format, &current_arg, 0);
	va_end(current_arg);
	return (count);
}

int main()
{
	printall(4, 1, 2, 3, 4);
	return (0);
}
