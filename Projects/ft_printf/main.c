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

	test = ft_strdup("Hello");
	c = "test";
	printf("PRINTF\n");
	printf("%d\n", printf("%p", test));
	printf("FT_PRINTF\n");
	printf("%d\n", ft_printf("%p", test));
	return (0);
}
