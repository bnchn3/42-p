#include <libft.h>

char *ft_octal_convert(unsigned int n)
{
  char *result;
  char *digit;
  int power;

  result = ft_strdup("");
  power = 0;
  while(ft_power(8, power) <= n)
    power++;
  power--;
  while (power >= 0)
  {
    digit = ft_unsigned_itoa(n / ft_power(8, power));
    ft_strpstr(&result, digit);
    free(digit);
    n %= ft_power(8, power);
    power--;
  }
  return (result);
}
