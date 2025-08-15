#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf.c"
#include "ft_printf_utils.c"
#include <limits.h>

int	main(void)
{
	printf("%x\n", LONG_MAX);
	ft_printf("%x\n", LONG_MAX);
	return (0);
}
