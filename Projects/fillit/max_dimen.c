<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_dimen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:15:39 by bchan             #+#    #+#             */
/*   Updated: 2017/12/18 11:17:19 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
=======
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
>>>>>>> 105d5fefbf76fdfa26ce229ac33105184e0f15d4
}

int max_width(char ***tetri)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 105d5fefbf76fdfa26ce229ac33105184e0f15d4
}

int find_length(char **tetri)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 105d5fefbf76fdfa26ce229ac33105184e0f15d4
}

int max_length(char ***tetri)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 105d5fefbf76fdfa26ce229ac33105184e0f15d4
}
