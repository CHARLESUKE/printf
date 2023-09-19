#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}

			if (*format == 'c')
			{
				/* Handle character specifier */
				char c = va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				/* Handle string specifier */
				char *str = va_arg(args, char *);
				while (*str)
				{
					write(1, str, 1);
					str++;
					printed_chars++;
				}
			}
			else if (*format == '%')
			{
				/* Handle '%' specifier */
				write(1, "%", 1);
				printed_chars++;
			}
		}
		else
		{
			/* Regular character, write it to stdout */
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}

	va_end(args);

	return (printed_chars);
}

