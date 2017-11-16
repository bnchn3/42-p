/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:48:09 by bchan             #+#    #+#             */
/*   Updated: 2017/11/06 16:06:39 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == *s2 && *s1 != '*')
		return (match(s1 + 1, s2 + 1));
	else if (*s1 == '*' && *s2 == '*')
		return (match(s1 + 1, s2));
	else if (*s2 == '*' && *s1 == '\0')
		return (match(s1, s2 + 1));
	else if (*s2 == '*')
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	else
		return (0);
}
