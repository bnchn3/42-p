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
	printf("%d\n", printf("%#o", 0));
	printf("FT_PRINTF\n");
	printf("%d\n", ft_printf("%#o", 0));
	return (0);
}
