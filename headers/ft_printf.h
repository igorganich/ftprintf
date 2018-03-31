#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define returner(parser) return (parser->wid_present ? ft_max_of_two(parser->wid, 1) : 1);

int	ft_printf(const char *format, ...);
#endif
