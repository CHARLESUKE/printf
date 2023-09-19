#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char current_char;

	va_start(args, format);

	while ((current_char = *format))
	{
		if (current_char != '%')
		{
			putchar(current_char);
			printed_chars++;
		}
		else
		{
			/* Handle format specifier */
			current_char = *(++format);
			switch (current_char)
			{
				case 'd':
					printed_chars += printf("%d", va_arg(args, int));
					break;
				case 'i':
					printed_chars += printf("%d", va_arg(args, int));
					break;
				case 'u':
					printed_chars += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					printed_chars += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					printed_chars += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					printed_chars += printf("%X", va_arg(args, unsigned int));
					break;
				case 'c':
					putchar(va_arg(args, int));
					printed_chars++;
					break;
				case 's':
					printed_chars += printf("%s", va_arg(args, char *));
					break;
				case 'p':
					printed_chars += printf("%p", va_arg(args, void *));
					break;
				case '%':
					putchar('%');
					printed_chars++;
					break;
				default:
					putchar('%');
					putchar(current_char);
					printed_chars += 2;
					break;
			}
		}
		format++;
	}

	va_end(args);
	return printed_chars;
}
