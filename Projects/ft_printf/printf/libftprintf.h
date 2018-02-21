/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:00:36 by bchan             #+#    #+#             */
/*   Updated: 2018/02/21 13:16:26 by bchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct	s_print
{
	char		*flags;
	int			width;
	int			precision;
	char		spec;
	size_t		printed;
	int			null;
}				t_print;

int				check_spec(char c);
char			get_spec(const char *format);
int				number_spec(char c);
char			*apply_flag(t_print *form, char *result);
char			*apply_width(t_print *form, char *result);
int				find_zeroes(char *save);
int				find_digits(char *save);
void			remove_zero(t_print *form, char *save, char *result);
char			*add_zero(t_print *form, char *save, char *result);
char			*apply_precision(char *temp, char *result, t_print *form);
char			*modify_string(t_print *form, char *result);
char			*pull_int(t_print *form, va_list ap, char c);
char			*pull_un_int(t_print *form, va_list ap, char c);
char			*pull_string(t_print *form, va_list ap);
char			*pull_voidp(t_print *form, va_list ap);
char			*length_hh(t_print *form, va_list ap, char c);
char			*length_h(t_print *form, va_list ap, char c);
char			*length_l(t_print *form, va_list ap, char c);
char			*length_ll(t_print *form, va_list ap, char c);
char			*length_j(t_print *form, va_list ap, char c);
char			*length_z(t_print *form, va_list ap, char c);
char			*length_none(t_print *form, va_list ap, char c);
t_print			*new_form(size_t printed);
t_print			*get_form(const char *format, t_print *form, va_list ap);
void			form_del(t_print *form);
char			*pull_longp(t_print *form, va_list ap);
char			*pull_intp(t_print *form, va_list ap);
char			*find_save(char c, char *result, t_print *form);
char			*wchar_dup(wchar_t chr);
char			*wstr_dup(wchar_t *str);
char			*modify_double(t_print *form, char *result);
int				ft_printf(const char *format, ...);

#endif
