#include <inttypes.h>
#include <sys/types.h>
#include "../../libft/includes/libft.h"

unsigned int	ft_printf_get_len_nbr(uintmax_t number, char *base)
{
	size_t			size;
	unsigned int	i;

	size = ft_strlen(base);
	i = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= size;
		i++;
	}
	return (i);
}
