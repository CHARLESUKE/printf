#include <stdio.h>
#include <stdarg.h>

#define BUFF_SIZE 256

int custom_printf(const char *format, ...);
int print_binary(int num);
/*Uncomment the main function to test custom_printf.*/
int main(void)
{
	custom_printf("Character: %c\n", 'A');
	custom_printf("String: %s\n", "Hello, World!");
	custom_printf("Percent: %%\n");
	custom_printf("Integer: %d\n", 42);
	custom_printf("Binary: %d\n", 42);

	return (0);
}

int custom_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, const char *));
					break;
				case '%':
					putchar('%');
					count++;
					break;
				case 'd':
					count += printf("%d", va_arg(args, int));
					break;
				case 'b':
					count += print_binary(va_arg(args, int));
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

int print_binary(int num)
{
	char buffer[BUFF_SIZE];
	int count = 0;
	int index = 0;

	if (num == 0)
	{
		putchar('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			buffer[index++] = num % 2 + '0';
			num = num / 2;
		}

		buffer[index] = '\0';

		for (int i = index - 1; i >= 0; i--)
		{
			putchar(buffer[i]);
			count++;
		}
	}

	return (count);
}

