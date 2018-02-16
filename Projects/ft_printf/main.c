#include <stdio.h>
#include <inttypes.h>
#include "libft/libft.h"
#include <locale.h>
#include <wchar.h>
#include "printf/libftprintf.h"

int	main(void)
{
	char	*test;
	char	*c;

	test = "{%#x}";
	c = "test";
	printf("PRINTF\n");
	printf("%d\n", printf("%lu", 4294967295));
	printf("FT_PRINTF\n");
	printf("%d\n", ft_printf("%U", 4294967295));
	return (0);
}
