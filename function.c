#include "main.h"

int custom_printf(const char *format, ...);

int main(void)
{
	custom_printf("Character: %c\n", 'A');
	custom_printf("String: %s\n", "Hello, World!");
	custom_printf("Percent: %%\n");
	custom_printf("Integer: %d\n", 42);
	custom_printf("Binary: %b\n", 42);

	return (0);
}
int custom_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int (count);
	char buffer[BUFF_SIZE];

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += handle_write_char(va_arg(args, int), buffer, 0, 0, 0, 0);
					break;
				case 's':
					count += print_string(args, buffer, 0, 0, 0, 0);
					break;
				case '%':
					count += print_percent(args, buffer, 0, 0, 0, 0);
					break;
				case 'd':
					count += print_int(args, buffer, 0, 0, 0, 0);
					break;
				case 'b':
					count += print_binary(args, buffer, 0, 0, 0, 0);
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

