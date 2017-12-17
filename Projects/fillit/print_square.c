void  twod_memcpy(char **dest, char **src, t_coor coor, char c)
{
  int i;
  int j;
  int x;
  int y;

  i = 0;
  x = coor->row;
  y = coor->col;
  while(src[i])
  {
    j = 0;
    while(src[i][j])
    {
      dest[x][y] = c;
      y++;
      j++;
    }
    x++;
    i++;
  }
}
