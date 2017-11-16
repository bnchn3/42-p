/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:51:57 by bchan             #+#    #+#             */
/*   Updated: 2017/11/01 18:25:06 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_params(char **arg)
{
	int		i;
	int		j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			ft_putchar(arg[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*store;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) < 0)
		{
			*store = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = *store;
			i = 1;
		}
		else
			i++;
	}
	ft_print_params(argv);
	return (0);
}
