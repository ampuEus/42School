#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, unsigned int *counter)
{
	if (!string)
		string = "(null)";
	while (*string)
		*counter += write(1, string++, 1);
}

void	put_digit(long long int number, int base, unsigned int *counter)
{
	char	hexadecimal[] = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*counter += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, counter);
	*counter += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	unsigned int counter = 0;
	va_list	args;
	va_start(args, format);

	while (*format)
	{
		if ((*format == '%') \
			&& ((*(format + 1) == 's') \
				|| (*(format + 1) == 'd') \
				|| (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(args, char *), &counter);
			else if (*format == 'd')
				put_digit((long long int)va_arg(args, int), 10, &counter);
			else if (*format == 'x')
				put_digit((long long int)va_arg(args, unsigned int), 16, &counter);
		}
		else
			counter += write(1, format, 1);
		format++;
	}
	return (va_end(args), counter);
}
