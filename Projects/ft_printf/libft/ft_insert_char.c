#include "libft.h"

char *ft_insert_char(char *s, char c, int index)
{
  char *temp;
  int i;
  int j;

  temp = ft_strnew(ft_strlen(s) + 1);
  i = 0;
  j = 0;
  while(s[i])
  {
    if (j == index)
      temp[j++] = c;
    temp[j++] = s[i++];
  }
  free(s);
  s = temp;
  return (s);
}
