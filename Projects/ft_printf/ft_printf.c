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

typedef struct	s_print
{
	char *flags;
	int		width;
	int		precision;
	char	spec;
}								t_print;

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

int number_spec(char c)
{
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

	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||
			c == 'g' || c == 'G')
		return (force_dec(result));
	if (c == 'd' || c == 'i')
		return (result);
	tmp1 = ft_strdup(result);
	if ((c == 'o' || c == 'O') && result[0] != '0')
		tmp2 = ft_strjoin("0", tmp1);
	if (c == 'x' && result[0] != '0')
		tmp2 = ft_strjoin("0x", tmp1);
	if (c == 'X' && result[0] != '0')
		tmp2 = ft_strjoin("0X", tmp1);
	ft_strcpy(result, tmp2);
	free(tmp1);
	free(tmp2);
	return (ft_strdup(result));
}

char *apply_flag(t_print form, char *result)
{
	char *temp;

	temp = NULL;
	if (form->spec == 'd' || form->spec == 'i')
	{
		if (ft_strchr(form->flags, '+') && ft_atoi(result) >= 0)
			temp = ft_strjoin("+", result);
		else if (ft_strchr(form->flags, ' ') && ft_atoi(result >= 0))
			temp = ft_strjoin(" ", result);
	}
	if (ft_strchr(form->flags, '#') && number_spec(form->spec))
		temp = apply_pound(form->spec, result);
	if (temp != result)
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
	else if (temp[0] == '0' && (result[0] == ' ' || result[0] == '+' ||
					result[0] == '-'))
	{
		s = ft_strdup(result);
		while (wid > 0)
		{
			s = ft_insert_char(s, '0', 1);
			wid--;
		}
	}
	else
		s = ft_strjoin(temp, result);
	return (s);
}

char *apply_width(t_print form, char *result)
{
	char *temp;
	char *save;

	if (form->width <= (int)ft_strlen(result))
		return (result);
	temp = ft_strnew_char(form->width - ft_strlen(result), ' ');
	save = NULL;
	if (ft_strchr(form->flags, '0') && (number_spec(form->spec)))
		temp = ft_memset(temp, '0', ft_strlen(temp));
	if (ft_strchr(form->flags, '-'))
		save = ft_strjoin(result, (temp = ft_memset(temp, ' ', ft_strlen(temp))));
	else
		save = add_lead(result, temp, form->width - ft_strlen(result));
	free(result);
	free(temp);
	return (save);
}

int find_zeroes(char *save)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (save[i] == ' ')
		i++;
	while (save[i] == '0')
	{
		count++;
		i++;
	}
	return (count);
}

int find_digits(char *save)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (save[i] == '0' || save[i] == ' ')
		i++;
	while (ft_isdigit(save[i]))
	{
		count++;
		i++;
	}
	return (count);
}

void remove_zero(t_print form, char *save, char *result)
{
	char *temp;

	ft_memmove(save, save + 1, ft_strlen(save));
	if (form->width)
	{
		temp = &(save[ft_strlen(save)]);
		if (ft_strchr(form->flags, '-'))
			ft_meminsert(temp, ' ', 1);
		else
			ft_meminsert(result, ' ', ft_strlen(result));
	}
}

char *add_zero(t_print form, char *save, char *result)
{
	char *temp;

	while (find_digits(save) + find_zeroes(save) < form->precision)
	{
		ft_meminsert(save, '0', ft_strlen(save));
		if (form->width)
		{
			temp = &(save[ft_strlen(save)]);
			if (ft_strchr(form->flags, '-') && *(temp - 1) == ' ')
				ft_memmove(temp - 1, temp, 1);
			else if (!(ft_strchr(form->flags, '-')) && *result == ' ')
			{
				ft_memmove(result, result + 1, ft_strlen(result));
				save--;
			}
		}
	}
	save = ft_strdup(result);
	free(result);
	return (save);
}

char *precision_int(char *result, t_print form)
{
	char *save;

	if (ft_atoi(result) == 0 && form->precision == 0)
		return (ft_memset(result, ' ', ft_strlen(result)));
	save = result;
	while (!(ft_isdigit(*save)))
		save++;
	if (find_digits(save) > form->precision)
		while (find_zeroes(save))
			remove_zero(form, save, result);
	else if (find_digits(save) + find_zeroes(save) > form->precision)
		while (find_digits(save) + find_zeroes(save) > form->precision)
			remove_zero(form, save, result);
	else
			result = add_zero(form, save, result);
	return (result);
}

char *precision_oct(char *result, t_print form)
{
	char *save;

	if (ft_atoi(result) == 0 && form->precision == 0)
		return (ft_memset(result, ' ', ft_strlen(result)));
	save = result;
	while (!(ft_isdigit(*save)))
		save++;
	if (ft_strchr(form->flags, '#'))
		save++;
	if (find_digits(save) > form->precision)
		while (find_zeroes(save))
			remove_zero(form, save, result);
	else if (find_digits(save) + find_zeroes(save) > form->precision)
		while (find_digits(save) + find_zeroes(save) > form->precision)
			remove_zero(form, save, result);
	else
		result = add_zero(form, save, result);
	return (result);
}

char *precision_hex(char *result, t_print form)
{
	char *save;

	if (ft_atoi(result) == 0 && form->precision == 0)
		return (ft_memset(result, ' ', ft_strlen(result)));
	save = result;
	while (!(ft_isdigit(*save)))
		save++;
	if (ft_strchr(form->flags, '#'))
		save += 2;
	if (find_digits(save) > form->precision)
		while (find_zeroes(save))
			remove_zero(form, save, result);
	else if (find_digits(save) + find_zeroes(save) > form->precision)
		while (find_digits(save) + find_zeroes(save) > form->precision)
			remove_zero(form, save, result);
	else
		result = add_zero(form, save, result);
	return (result);
}

char *minimum_digits(char c, char *result, t_print form)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U')
			result = precision_int(result, form);
	if (c == 'o' || c == 'O')
			result = precision_oct(result, form);
	if (c == 'x' || c == 'X')
			result = precision_hex(result, form);
	return (result);
}

char *max_char(char *result, const char *wid, int prec, char *temp)
{
	int left;
	char *save;

	left = 0;
	save = result;
	if (find_flag(wid, '-'))
		left = 1;
	while (ft_strncmp(temp, save, ft_strlen(temp)) != 0)
		save++;
	save[prec] = '\0';
	if (ft_atoi(wid) && ft_strlen(result) < ft_atoi(wid))
	{
		if (left == 1)
			while (ft_strlen(result) < ft_atoi(wid))
				ft_strpstr(&result, " ");
		else
			while (ft_strlen(result) < ft_atoi(wid))
				result = ft_insert_char(result, ' ', 0);
	}
	return (result);
}

char *apply_precision(char *temp, char *result, t_print form)
{
	char c;

	c = form->spec;
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'o' ||
			c == 'O' || c == 'x' || c == 'X')
		result = minimum_digits(c, result, form);
	else if (c == 's')
		result = max_char(result, wid, prec, temp);
	return (result);
}

char *modify_string(t_print form, char *result)
{
	char *temp;

	temp = ft_strdup(result);
	result = apply_flag(form, result);
	result = apply_width(form, result);
	result = apply_precision(temp, result, form);
	free(temp);
	return (result);
}

char *pull_int(t_print form, va_list ap, char c)
{
	int arg;
	char *result;

	arg = va_arg(ap, int);
	if (c == 'd' || c == 'i')
		result = ft_itoa(arg);
	else
		result = ft_strdup(&arg);
	result = modify_string(form, result);
	return (result);
}

char *pull_un_int(t_print form, va_list ap, char c)
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
	{
		i = 0;
		result = ft_hex_convert(arg);
		while (result[i])
		{
			result[i] = (char)ft_toupper(result[i]);
		  i++;
		}
	}
	result = modify_string(form, result);
	return (result);
}

char *pull_string(t_print form, va_list ap)
{
	char *arg;

	arg = ft_strdup(va_arg(ap, char *));
	arg = modify_string(form, arg);
	return (arg);
}

char *pull_voidp(t_print form, va_list ap)
{
	void *arg;
	char *result;
	char *temp;

	arg = va_arg(ap, void *);
	temp = ft_hex_convert((unsigned int)arg);
	result = ft_strjoin("0x", temp);
	free(temp);
	result = modify_string(form, result);
	return (result);
}

char *pull_char(t_print form, va_list ap)
{
	char arg;
	char *result;

	arg = va_arg(ap, char);
	result = ft_itoa((int)arg);
	result = modify_string(form, result);
	return (result);
}

char *pull_un_char(t_print form, va_list ap, char c)
{
	unsigned char arg;
	char *result;

	arg = va_arg(ap, unsigned char);
	if (c == 'u')
		result = ft_unsigned_itoa((unsigned int)arg);
	if (c == 'o')
		result = ft_octal_convert((unsigned int)arg);
	if (c == 'x')
		result = ft_hex_convert((unsigned int)arg);
	if (c == 'X')
	{
		i = 0;
		result = ft_hex_convert((unsigned int)arg);
		while (result[i])
		{
			result[i] = (char)ft_toupper(result[i]);
		  i++;
		}
	}
	result = modify_string(form, result);
	return (result);
}

char *length_hh(t_print form, va_list ap, char c)
{
		if (c == 'd' || c == 'i')
			return (pull_char(form, ap));
		if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
			return (pull_un_char(form, ap, c));
		if (c == 'n')
			return (pull_charp(form, ap));
		return (length_none(form, ap ,c));
}

char *length_h(t_print form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_short(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_short(form, ap, c));
	if (c == 'n')
		return (pull_shortp(form, ap));
	return (length_none(form, ap ,c));
}

char *length_l(t_print form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (pull_long(form, ap, c));
	if (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		return (pull_un_long(form, ap, c));
	if (c == 'c' || c == 'C')
		return (pull_wint(form, ap, c));
	if (c == 's' || c == 'S')
		return (pull_wchar(form, ap, c));
	if (c == 'n')
		return (pull_longp(form, ap, c));
	return (length_none(form, ap, c));
}

char *length_ll(t_print form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_long_long(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_long_long(form, ap, c));
	if (c == 'n')
		return (pull_long_longp(form, ap));
	return (length_none(form, ap ,c));
}

char *length_j(t_print form, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (pull_intmax(form, ap));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_uintmax(form, ap, c));
	if (c == 'n')
		return (pull_intmaxp(form, ap));
	return (length_none(form, ap ,c));
}

char *length_z(t_print form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_sizet(form, ap));
	if (c == 'n')
		return (pull_sizetp(form, ap));
	return (length_none(form, ap ,c));
}

char *length_none(t_print form, va_list ap, char c)
{
	if (c == 'd' || c == 'i' || c == 'c')
		return (pull_int(form, ap, c));
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (pull_un_int(form, ap, c));
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' ||
			c == 'a' || c == 'A')
		return (pull_double(form, ap, c));
	if (c == 's')
		return (pull_string(form, ap));
	if (c == 'p')
		return (pull_voidp(form, ap));
	if (c == 'n')
		return (pull_intp(form, ap, c));
	if (c == 'D' || c == 'U' || c == 'O' || c == 'C' || c == 'S')
		return(length_l(form, ap, c));
	return (NULL);
}

char	*check_length(const char *format, va_list ap, t_print form)
{
	int i;

	i = 0;
	while(!(check_spec(format[i])))
		i++;
	if (format[i - 1] == 'h')
	{
		if (format[i - 2] == 'h')
			return (length_hh(form, ap, format[i]));
		return (length_h(form, ap, format[i]));
	}
	if (format[i - 1] == 'l')
	{
		if (format[i - 2] == 'l')
			return (length_ll(form, ap, format[i]));
		return (length_l(form, ap, format[i]));
	}
	if (format[i - 1] == 'j')
		return (length_j(form, ap, format[i]));
	if (format[i - 1] == 'z')
		return (length_z(form, ap, format[i]));
	return (length_none(form, ap, format[i]));
}

t_print new_form(void)
{
	t_print form;

	form = (t_print)malloc(sizeof(t_print));
	form->flags = ft_strdup("");
	form->width = 0;
	form->precision = 0;
	form->spec = 0;
	return (form);
}

t_print get_form(const char *format, t_print form)
{
	int i;

	i = 1;
	while (format[i] == '+' || format[i] == '-' || format[i] == ' ' ||
				format[i] == '0' || format[i] == '#')
		form->flags = ft_strpchar(&(form->flags), format[i++]);
	if (ft_atoi(&(format[i])))
	{
		form->width = ft_atoi(&(format[i]));
		while (ft_isdigit(format[i]))
			i++;
	}
	if (format[i] == '.')
		form->precision = ft_atoi(&(format[i + 1]));
	form->spec = get_spec(format);
	return (form);
}

char *print_arg(const char *format, va_list ap)
{
	char *result;
	t_print form;

	if (format[1] == '%')
		return (ft_strdup("%"));
	form = new_form();
	form = get_form(format, form);
	result = check_length(format, ap, form);
	return (result);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	char *result;
	size_t	i;
	char *temp;

	result = 0;
	i = 0;
	va_start(ap, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			result = ft_strpstr(&result, temp = print_arg(&(format[i++]), ap));
			free(temp);
			while(!(check_spec(format[i++])))
				if (format[i - 1] == '%')
					break ;
		}
		else
			result = ft_strpchar(&result, format[i++]);
	}
	ft_putstr(result);
	i = ft_strlen(result);
	free(result);
	va_end(ap);
	return (i);
}
