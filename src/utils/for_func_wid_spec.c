#include "../../libft/includes/libft.h"

void	ft_printf_func_wid_spec(int len, int wid, char c)
{
	while (len < wid)
	{
		ft_putchar(c);
		len++;
	}//change here mb?
}
