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
	printf("%d\n", printf("@moulitest: %c", 0));
	printf("FT_PRINTF\n");
	printf("%d\n", ft_printf("@moulitest: %c", 0));
	return (0);
}
