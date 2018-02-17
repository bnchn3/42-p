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
	printf("%d\n", printf("% 4.5i", 42));
	printf("FT_PRINTF\n");
	printf("%d\n", ft_printf("% 4.5i", 42));
	return (0);
}
