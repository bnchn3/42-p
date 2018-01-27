/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:28:42 by bchan             #+#    #+#             */
/*   Updated: 2018/01/22 11:28:44 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int check_spec(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
			c == 's' || c == 'p' || c == 'c' || c == 'D' || c == 'U' || c == 'O' ||
			c == 'S' || c == 'C' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||
			c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'n')
			return (1);
	return (0);
}

char *force_dec(char *result)
{
	int i;

	i = 0;
	while(result[i])
	{
		if (result[i] == '.')
			return (result);
		i++;
	}
	ft_strpstr(&result, ".")
	return (result);
}

char *apply_pound(char c, char *result)
{
	char *tmp1;
	char *tmp2;
	char *save;

	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||
			c == 'g' || c == 'G')
		return (force_dec(result));
	save = result;
	while(*save == '-' || *save == '+' || *save == ' ')
		save++;
	tmp1 = ft_strdup(save);
	if ((c == 'o' || c == 'O') && save[0] != '0')
		tmp2 = ft_strjoin("0", tmp1);
	if (c == 'x' && save[0] != '0')
		tmp2 = ft_strjoin("0x", tmp1);
	if (c == 'X' && save[0] != '0')
		tmp2 = ft_strjoin("0X", tmp1);
	ft_strcpy(save, tmp2);
	free(tmp1);
	free(tmp2);
	return (ft_strdup(result));
}

char *apply_flag(const char *format, char c, char *result)
{
	char *temp;
	int i;

	i = 0;
	temp = NULL:
	while (!(check_spec(format[i])))
		i++;
	if (format[i] != 's' && format[i] != 'S' && format[i] != 'c' &&
			format[i] != 'C' && format[i] != 'p' && format[i] != 'n')
	{
		if (c == '+' && result[0] != '-')
			temp = ft_strjoin("+", result);
		if (c == ' ' && result[0] != '-' && (!(ft_strchr(format, '+')) ||
				ft_strchr(format, '+') > &(format[i])))
			temp = ft_strjoin(" ", result);
		if (c == '#')
			temp = apply_pound(format[i], result);
	}
	if (temp)
	{
		free(result);
		result = temp;
	}
	return (result);
}

char *apply_width(const char *format, char *result, int wid)
{
	int left;
	char *temp;
	char *save;

	left = 0;
	if (wid <= (int)ft_strlen(result))
		return (result);
	temp = ft_strnew(wid - ft_strlen(result));
	temp = ft_memset(temp, ' ', wid - ft_strlen(result));
	save = format;
	while(*save != '%')
	{
		if (*save == '-')
			left = 1;
		if (*save == '0' && (ft_atoi(result)))
			temp = ft_memset(temp, '0', ft_strlen(temp));
		save--;
	}
	if (left == 1)
		save = ft_strjoin(result, (temp = ft_memset(temp, ' ', ft_strlen(temp))));
	else
		save = ft_strjoin(temp, result);
	free(result);
	free(temp);
	return (save);
}

char *apply_precision(const char *format, char *result, int wid)
{
	int i;

	i = 0;
	while(!(check_spec(format[i])))
		i++;
	if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i' || format[i] ==
			'u' || format[i] == 'U' || format[i] == 'o' || format[i] == 'O' ||
			format[i] == 'x' || format[i] == 'X')
		result = minimum_digits(format, result, wid);
	else if (format[i] == 's')
		result = max_char(format, result, wid);
	return (result);
}

char *modify_string(const char *format, char *result)
{
	int i;
	int wid;

	i = 1;
	while (format[i] == '+' || format[i] == ' ' || format[i] == '#' ||
				format[i] == '-' || format[i] == '0')
	{
		result = apply_flag(format, format[i], result);
		i++;
	}
	if ((wid = ft_atoi(&(format[i]))))
	{
		result = apply_width(&(format[i]), result, wid);
		while(format[i] >= '0' && format[i] <= '9')
			i++;
	}
	if (format[i] == '.' && ((wid = ft_atoi(&(format[i + 1]))) ||
			format[i + 1] == '0'))
		result = apply_precision(format, result, wid);
	return (result);
}

char *pull_int(const char *format, va_list ap, int spec)
{
	int arg;
	char *result;

	arg = va_arg(ap, int);
	if (format[spec] == 'd' || format[spec] == 'i')
		result = ft_itoa(arg);
	else
		result = ft_strdup(&arg);
	result = modify_string(format, result);
	return (result);
}

char *pull_un_int(const char *format, va_list ap, int spec)
{
	unsigned int arg;
	char *result;

	arg = va_arg(ap, unsigned int);
	if (format[spec] == 'u')
		result = ft_unsigned_itoa(arg);
	if (format[spec] == 'o')
		result = ft_octal_convert(arg);
	if (format[spec] == 'x')
		result = ft_hex_convert(arg);
	if (format[spec] == 'X')
		result = ft_toupper(ft_hex_convert(arg));
	result = modify_string(format, result);
	return (result);
}

char *pull_string(const char *format, va_list ap, int spec)
{
	char *arg;

	arg = va_arg(ap, char *);
	arg = modify_string(format, arg);
	return (arg);
}

char *pull_voidp(const char *format, va_list ap, int spec)
{
	void *arg;
	char *result;
	char *temp;

	arg = va_arg(ap, void *);
	temp = ft_hex_convert(arg);
	result = ft_strjoin("0x", temp);
	free(temp);
	result = modify_string(format, result);
	return (result);
}

char *length_l(const char *format, va_list ap, int i)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'D')
		return (pull_l_int(format, ap, i));
	if (format[i] == 'u' || format[i] == 'U' || format[i] == 'o' || format[i] ==
			'O' || format == 'x' || format == 'X')
		return (pull_un_l_int(format, ap, i));
	if (format[i] == 'c' || format[i] == 'C')
		return (pull_wint(format, ap, i));
	if (format[i] == 's' || format[i] == 'S')
		return (pull_wchar(format, ap, i));
	if (format[i] == 'n')
		return (pull_l_intp(format, ap, i));
	return (length_none(format, ap, i));
}

char *length_none(const char *format, va_list ap, int i)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'c')
		return (pull_int(format, ap, i));
	if (format[i] == 'u' || format[i] == 'o' || format == 'x' || format == 'X')
		return (pull_un_int(format, ap, i));
	if (format[i] == 'f' || format[i] == 'F' || format[i] == 'e' ||
			format[i] == 'E' || format[i] == 'g' || format[i] == 'G' ||
			format[i] == 'a' || format[i] == 'A')
		return (pull_double(format, ap, i));
	if (format[i] == 's')
		return (pull_string(format, ap, i));
	if (format[i] == 'p')
		return (pull_voidp(format, ap, i));
	if (format[i] == 'n')
		return (pull_intp(format, ap, i));
	if (format[i] == 'D' || format[i] == 'U' || format[i] == 'O' || format[i] ==
			'C' || format[i] == 'S')
		return(length_l(format, ap, i));
	return (NULL);
}

char	*check_length(const char *format, va_list ap)
{
	int i;

	i = 0;
	while(!(check_spec(format[i])))
		i++;
	if (format[i - 1] == 'h')
	{
		if (format[i - 2] == 'h')
			return (length_hh(format, ap));
		return (length_h(format, ap));
	}
	if (format[i - 1] == 'l')
	{
		if (format[i - 2] == 'l')
			return (length_ll(format, ap));
		return (length_l(format, ap));
	}
	if (format[i - 1] == 'j')
		return (length_j(format, ap));
	if (format[i - 1] == 'z')
		return (length_z(format, ap));
	return (length_none(format, ap, i));
}

size_t print_arg(const char *format, va_list ap)
{
	char *result;

	if (format[1] == '%')
	{
		ft_putchar('%');
		return ((size_t)1);
	}
	result = check_length(format, ap);
	if (result)
	{
		ft_putstr(result);
		return (ft_strlen(result));
	}
	return (-1);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	size_t	result;
	int	i;

	result = 0;
	i = 0;
	va_start(ap, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			result += print_arg(&(format[i++]), ap);
			while(!(check_spec(format[i++])))
				if (format[i - 1] == '%')
					break ;
		}
		else
		{
			ft_putchar(format[i++]);
			result++;
		}
	}
	va_end(ap);
	return (result);
}
