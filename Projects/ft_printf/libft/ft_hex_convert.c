#include <libft.h>

static char *hex(int n)
{
  char key[6];
  int i;
  char c;
  char *result;

  i = 0;
  c = 'a';
  result = ft_strnew(1);
  while (i < 6)
    key[i++] = c++;
  n -= 10;
  result[0] = key[n];
  return (result);
}

char *ft_hex_convert(unsigned int n)
{
  char *result;
  char *digit;

  result = ft_strdup("");
  if (n == 0)
    ft_strpstr(&result, "0");
  while (n > 0)
  {
    if (n % 16 < 10)
      digit = ft_unsigned_itoa(n % 16);
    else
      digit = hex(n % 16);
    ft_strpstr(&result, digit);
    free(digit);
    n /= 16;
  }
  result = ft_strrev(result);
  return (result);
}
