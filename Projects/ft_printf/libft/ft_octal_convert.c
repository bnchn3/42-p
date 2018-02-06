#include <libft.h>

char *ft_octal_convert(unsigned int n)
{
  char *result;
  char *digit;

  result = ft_strdup("");
  if (n == 0)
    ft_strpstr(&result, "0");
  while (n > 0)
  {
    digit = ft_unsigned_itoa(n % 8);
    ft_strpstr(&result, digit);
    free(digit);
    n /= 8;
  }
  result = ft_strrev(result);
  return (result);
}
