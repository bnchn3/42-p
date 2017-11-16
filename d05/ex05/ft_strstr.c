/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:11:27 by bchan             #+#    #+#             */
/*   Updated: 2017/10/30 16:28:23 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find(char *savestr, char *substr)
{
	while (*substr)
	{
		if (*substr != *savestr)
			return (0);
		substr++;
		savestr++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*savestr;
	char	*substr;
	char	*pos;
	int		found;

	savestr = str;
	if (*to_find == '\0')
		return (str);
	while (*savestr)
	{
		if (*to_find == *savestr)
		{
			substr = to_find;
			pos = savestr;
			found = ft_find(savestr, substr);
			if (found == 1)
				return (pos);
		}
		savestr++;
	}
	return (0);
}
