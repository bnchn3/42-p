#include "libft.h"

static size_t	ft_intlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	while (n != 0)
	{
		n /= (unsigned int)10;
		len++;
	}
	return (len);
}

char			*ft_unsigned_itoa(unsigned int n)
{
	char	*result;
	int		i;

	result = (char *)ft_strnew(ft_intlen(n));
	if (result)
	{
		i = ft_intlen(n) - 1;
		if (n == 0)
			result[0] = '0';
		while (n != 0)
		{
			result[i--] = n % (unsigned int)10 + '0';
			n /= (unsigned int)10;
		}
	}
	return (result);
}
