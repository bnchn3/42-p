#include "libft.h"

void *ft_meminsert(void *s, int c, int n)
{
  ft_memmove(s + 1, s, n);
  *(char *)s = c;
  return (s);
}
