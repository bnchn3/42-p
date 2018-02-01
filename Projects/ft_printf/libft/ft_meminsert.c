#include "libft.h"

void *ft_meminsert(void *s, int c, int n)
{
  ft_memmove(s + 1, s, n);
  s[0] = c;
  return (s);
}
