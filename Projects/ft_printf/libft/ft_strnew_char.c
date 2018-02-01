#include "libft.h"

char *ft_strnew_char(size_t n, char c)
{
  char *result;

  result = ft_strnew(n);
  result = ft_memset(result, c, n);
  return (result);
}
