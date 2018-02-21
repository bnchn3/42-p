/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:34:09 by bchan             #+#    #+#             */
/*   Updated: 2018/02/19 13:34:11 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double  round_num(long double n)
{
  long double save;

  save = n;
  if (n < 1 && n > -1)
    return (0);
  while (save >= 10 || save <= -10)
    save /= 10;
  while (save >= 1)
    save--;
  while (save <= -1)
    save++;
  return (n - save);
}

static long double  mod_double(long double n, long double i)
{
  if (n < 0)
  {
    if (i > 0)
      i *= -1;
    while (n - i <= i)
      n -= i;
  }
  if (n > 0)
  {
    if (i < 0)
      i *= -1;
    while (n - i >= i)
      n -= i;
  }
  return (n);
}

static long double  get_decimal(long double n)
{
  int count;

  count = 0;
  if (n < 0)
    n *= -1;
  while (count < 19)
  {
    n *= 10;
    count++;
  }
  return (round_num(n));
}

static char *get_number(long double save, char *result)
{
  int isneg;

  isneg = 0;
  if (save < 0)
  {
    isneg = 1;
    save *= -1;
  }
  while (save >= 10)
  {
    ft_strpchar(&result, (int)(mod_double(save, 10) + '0'));
    save /= 10;
  }
  ft_strpchar(&result, (int)save + '0');
  if (isneg == 1)
    ft_strpchar(&result, '-');
  result = ft_strrev(result);
  return (result);
}

char  *ft_dtoa(long double n)
{
  char  *result;
  char  *temp;
  long double save;
  int i;

  result = ft_max_itoa((long long)n);
  save = round_num(n);
  ft_strpchar(&result, '.');
  if (n - save != 0)
  {
    save = get_decimal(n - save);
    temp = ft_max_itoa((long long)save);
    ft_strpstr(&result, temp);
    ft_strdel(&temp);
  }
  else
  {
    i = 0;
    while (i++ < 19)
      ft_strpchar(&result, '0');
  }
  return (result);
}
