int find_width(char **tetri)
{
  int wid;
  int i;
  int j;

  wid = 1;
  i = 0;
  while(tetri[i])
  {
    j = 0;
    while(tetri[i][j])
    {
      if (j > wid)
        wid = j;
      j++;
    }
    i++;
  }
  return(wid);
}

int max_width(char ***tetri)
{
  int max;
  int i;

  max = 0;
  i = 0;
  while(tetri[i])
  {
    max += find_width(tetri[i]);
    i++;
  }
  return(max);
}

int find_length(char **tetri)
{
  int len;
  int i;
  int j;

  len = 1;
  i = 0;
  while(tetri[i])
  {
    if (i > len)
      len = i;
    i++;
  }
  return(len);
}

int max_length(char ***tetri)
{
  int max;
  int i;

  max = 0;
  i = 0;
  while(tetri[i])
  {
    max += find_length(tetri[i]);
    i++;
  }
  return(max);
}
