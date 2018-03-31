#include <stdio.h>
#include <unistd.h>
#include "headers/ft_printf.h"

int main()
{
	int ret1 = ft_printf("%#6o", 2500);
	printf("end");
	printf("\n");
	int ret2 = printf("%#6o", 2500);
	printf("end");
	printf("\n");
	printf("%d    %d\n", ret1, ret2);
	return (0);
}
