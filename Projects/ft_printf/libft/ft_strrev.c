#include <libft.h>

char *ft_strrev(char *s)
{
  int i;
  int j;
  char save;

  i = 0;
  j = ft_strlen(s) - 1;
  while (i <= j)
  {
    save = s[i];
    s[i++] = s[j];
    s[j--] = save;
  }
  return (s);
}
