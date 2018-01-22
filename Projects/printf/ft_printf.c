#include <stdarg.h>

int ft_printf(const char *format, va_list ap)
{
	int i;

	if (format[0] != '%')
	{
		ft_putstr(format);
		return ((int)ft_strlen(format));
	}
	va_start(ap, format);
	i = 0;
	while(format[i])
	{
		
	}
}
