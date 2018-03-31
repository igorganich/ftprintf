#ifndef HANDLE_FUNCS_H
# define HANDLE_FUNCS_H
# include <stdarg.h>
# include "ft_printf.h"
# include <stdint.h>
# include <sys/types.h>

typedef struct		s_prs
{
	int				grid : 1;
	int				zero : 1;
	int				minus : 1;
	int				plus : 1;
	int				space : 1;
	int				wid_present : 1;
	int				tochka_present : 1;
	unsigned int	wid;
	unsigned int	tochka;
	enum {
		none,
		key_hh,
		key_h,
		key_l,
		key_ll,
		key_j,
		key_z
	}				len;
}					t_prs;

ssize_t				ft_printf_func_pers(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_string(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_wstring(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_pointer(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_int(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_long(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_octal(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_unsigned(char **format, va_list *args,
		t_prs *parser);
ssize_t                         ft_printf_func_hex_big(char **format, va_list *args,
                t_prs *parser);
ssize_t				ft_printf_func_hex_small(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_char(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_wchar(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_null(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_binary(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_float(char **format, va_list *args,
		t_prs *parser);
ssize_t				ft_printf_func_charswritten(char **format, va_list *a,
		t_prs *parser);
ssize_t				ft_printf_func_uint(uintmax_t nbr, t_prs *parser, char *b,
		char *p);
typedef ssize_t		(*t_func)(char**, va_list*, t_prs*);
t_func			ft_printf_get_func(char c, int flag);

#endif

