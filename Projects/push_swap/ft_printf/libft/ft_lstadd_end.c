#include "libft.h"

void ft_lstadd_end(t_list **begin_list, t_list *new)
{
  t_list *lst;

  lst = *begin_list;
  while (lst->next != NULL)
    lst = lst->next;
  lst->next = new;
}
