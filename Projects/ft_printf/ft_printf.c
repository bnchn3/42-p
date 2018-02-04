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

char get_spec(const char *format)
{
	int i;

	i = 0;
	while(!(check_spec(format[i])))
		i++;
	return (format[i]);
}

int number_spec(const char *format)
{
	char c;

	c = get_spec(format);
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'n')
		return (0);
	return (1);
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
	if (number_spec(format))
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

char *add_lead(char *result, char *temp, int wid)
{
	char *s;

	if (temp[0] == '0' && result[0] == '0' && result[1] == 'x')
	{
		s = ft_strdup(result);
		while(wid > 0)
		{
			s = ft_insert_char(s, '0', 2);
			wid--;
		}
	}
	else
		s = ft_strjoin(temp, result);
	return (s);
}

char *apply_width(const char *format, char *result, int wid)
{
	int left;
	char *temp;
	char *save;

	left = 0;
	if (wid <= (int)ft_strlen(result))
		return (result);
	temp = ft_strnew_char(wid - ft_strlen(result), ' ');
	save = format;
	while(*save != '%')
	{
		if (*save == '-')
			left = 1;
		if (*save == '0' && (number_spec(format)))
			temp = ft_memset(temp, '0', ft_strlen(temp));
		save--;
	}
	if (left == 1)
		save = ft_strjoin(result, (temp = ft_memset(temp, ' ', ft_strlen(temp))));
	else
		save = add_lead(result, temp, wid);
	free(result);
	free(temp);
	return (save);
}

int find_zeroes(char *save)
{
	int i;

	i = 0;
	while (save[i] == '0')
		i++;
	return (i);
}

int find_digits(char *save)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (save[i] == '0')
		i++;
	while (ft_isdigit(save[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int find_flag(const char *wid, char c)
{
	char *temp;

	temp = wid;
	while (*temp != '%')
	{
		if (*temp == c)
			return (1);
		temp--;
	}
	return (0);
}

void remove_zero(const char *wid, char *save, char *result)
{
	int left;
	char *temp;

	left = 0;
	temp = wid;
	if (find_flag(wid, '-'))
		left = 1;
	ft_memmove(save, save + 1, ft_strlen(save));
	if (ft_atoi(wid))
	{
		temp = &(save[ft_strlen(save)]);
		if (left == 1)
			ft_meminsert(temp, ' ', 1);
		else
			ft_meminsert(result, ' ', ft_strlen(result));
	}
}

char *add_zero(const char *wid, char *save, char *result)
{
	int left;
	char *temp;

	left = 0;
	temp = wid;
	if (find_flag(wid, '-'))
		left = 1;
	while (find_digits(save) + find_zeroes(save) < prec)
	{
		ft_meminsert(save, '0', ft_strlen(save));
		if (ft_atoi(wid))
		{
			temp = &(save[ft_strlen(save)]);
			if (left == 1 && *(temp - 1) == ' ')
				ft_memmove(temp - 1, temp, 1);
			else if (left != 1 && *result == ' ')
				ft_memmove(result, result + 1, ft_strlen(result));
		}
	}
	save = ft_strdup(result);
	free(result);
	return (save);
}

char *precision_int(char *result, const char *wid, int prec)
{
	char *save;

	if (ft_atoi(result) == 0 && prec == 0)
		return (ft_memset(result, ' ', ft_strlen(result)));
	save = result;
	while (!(ft_isdigit(*save)))
		save++;
	if (find_digits(save) > prec)
		while (find_zeroes(save))
			remove_zero(wid, save, result);
	else if (find_digits(save) + find_zeroes(save) > prec)
		while (find_digits(save) + find_zeroes(save) > prec)
			remove_zero(wid, save, result);
	else
			result = add_zero(wid, save, result);
	return (result);
}

char *precision_oct(char *result, const char *wid, int prec)
{
	char *save;

	if (ft_atoi(result) == 0 && prec == 0)
		return (ft_memset(result, ' ', ft_strlen(result)));
	save = result;
	while (!(ft_isdigit(*save)))
		save++;
	if (find_flag(wid, '#'))
		save++;
	if (find_digits(save) > prec)
		while (find_zeroes(save))
			remove_zero(wid, save, result);
	else if (find_digits(save) + find_zeroes(save) > prec)
		while (find_digits(save) + find_zeroes(save) > prec)
			remove_zero(wid, save, result);
	else
		result = add_zero(wid, save, result);
	return (result);
}

char *precision_hex(char *result, const char *wid, int prec)
{
	char *save;

	if (ft_atoi(result) == 0 && prec == 0)
		return (ft_memset(result, ' ', ft_strlen(result)));
	save = result;
	while (!(ft_isdigit(*save)))
		save++;
	if (find_flag(wid, '#'))
		save += 2;
	if (find_digits(save) > prec)
		while (find_zeroes(save))
			remove_zero(wid, save, result);
	else if (find_digits(save) + find_zeroes(save) > prec)
		while (find_digits(save) + find_zeroes(save) > prec)
			remove_zero(wid, save, result);
	else
		result = add_zero(wid, save, result);
	return (result);
}

char *minimum_digits(char c, char *result, const char *wid, int prec)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U')
			result = precision_int(result, wid, prec);
	if (c == 'o' || c == 'O')
			result = precision_oct(result, wid, prec);
	if (c == 'x' || c == 'X')
			result = precision_hex(result, wid, prec);
	return (result);
}

char *max_char(char *result, const char *wid, int prec)
{
	char *temp;
	int left;

	temp = wid;
	left = 0;
	if (find_flag(wid, '-'))
		left = 1;
	ft_memmove(&(result[prec]), &(result[ft_strlen(result)]), 1);
	if (ft_atoi(wid))
	{
		if (left == 1)
			while (ft_atoi(wid) - prec > 0)
				result = ft_insert_char(result, ' ', prec++);
		else
			while (ft_atoi(wid) - prec++ > 0)
				result = ft_insert_char(result, ' ', 0);
	}
	return (result);
}

char *apply_precision(const char *format, char *result, const char *wid,
											int prec)
{
	char c;

	c = get_spec(format);
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'o' ||
			c == 'O' || c == 'x' || c == 'X')
		result = minimum_digits(c, result, wid, prec);
	else if (c == 's')
		result = max_char(result, wid, prec);
	return (result);
}

char *modify_string(const char *format, char *result)
{
	int i;
	const char *wid;

	i = 1;
	while (format[i] == '+' || format[i] == ' ' || format[i] == '#' ||
				format[i] == '-' || format[i] == '0')
	{
		result = apply_flag(format, format[i], result);
		i++;
	}
	wid = &(format[i]);
	if ((ft_atoi(wid))
	{
		result = apply_width(wid, result, ft_atoi(wid));
		while(format[i] >= '0' && format[i] <= '9')
			i++;
	}
	if (format[i] == '.')
		result = apply_precision(format, result, wid, ft_atoi(&(format[i + 1])));
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

char *pull_un_int(const char *format, va_list ap, char c)
{
	unsigned int arg;
	char *result;

	arg = va_arg(ap, unsigned int);
	if (c == 'u')
		result = ft_unsigned_itoa(arg);
	if (c == 'o')
		result = ft_octal_convert(arg);
	if (c == 'x')
		result = ft_hex_convert(arg);
	if (c == 'X')
		result = ft_toupper(ft_hex_convert(arg));
	result = modify_string(format, result);
	return (result);
}

char *pull_string(const char *format, va_list ap)
{
	char *arg;

	arg = va_arg(ap, char *);
	arg = modify_string(format, arg);
	return (arg);
}

char *pull_voidp(const char *format, va_list ap)
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

char *length_hh(const char *format, va_list ap, char c)
{
		if ()
}

char *length_l(const char *format, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (pull_l_int(format, ap, c));
	if (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		return (pull_un_l_int(format, ap, c));
	if (c == 'c' || c == 'C')
		return (pull_wint(format, ap, c));
	if (c == 's' || c == 'S')
		return (pull_wchar(format, ap, c));
	if (c == 'n')
		return (pull_l_intp(format, ap, c));
	return (length_none(format, ap, c));
}

char *length_none(const char *format, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'c')
		return (pull_int(format, ap, c));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_int(format, ap, c));
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' ||
			c == 'a' || c == 'A')
		return (pull_double(format, ap, c));
	if (c == 's')
		return (pull_string(format, ap));
	if (c == 'p')
		return (pull_voidp(format, ap));
	if (c == 'n')
		return (pull_intp(format, ap, c));
	if (c == 'D' || c == 'U' || c == 'O' || c == 'C' || c == 'S')
		return(length_l(format, ap, c));
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
			return (length_hh(format, ap, format[i]));
		return (length_h(format, ap, format[i]));
	}
	if (format[i - 1] == 'l')
	{
		if (format[i - 2] == 'l')
			return (length_ll(format, ap, format[i]));
		return (length_l(format, ap, format[i]));
	}
	if (format[i - 1] == 'j')
		return (length_j(format, ap, format[i]));
	if (format[i - 1] == 'z')
		return (length_z(format, ap, format[i]));
	return (length_none(format, ap, format[i]));
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
	char *result;
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
			result = ft_insert_char(result, format[i++], ft_strlen(result))
	}
	va_end(ap);
	return (ft_strlen(result));
}
