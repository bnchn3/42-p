#include "libft.h"

unsigned int ft_power(unsigned int base, int power)
{
  unsigned int result;

  result = base;
  if (power == 0)
    return (1);
  else
    result *= ft_power(base, power - 1);
  return (result);
}
