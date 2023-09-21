#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define I_MINUS 0x01




int write_number(int is_negative, int i, char buffer[], int flags, int width, int precision, int size);
long int convert_size_number(long int n, int size);


/************************* PRINT CHAR *************************/

/* Function prototype for handle_write_char */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);

/* Function definition for print_char */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	/* Call handle_write_char and return its result */
	return (handle_write_char(c, buffer, flags, width, precision, size));
}


/************************* PRINT A STRING *************************/

int print_string(va_list types, int flags, int width, int precision)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		/* Define I_MINUS as a hexadecimal value (you can adjust the value) */
		if (flags & I_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/

int print_percent(va_list types, int flags, int width, int precision)
{
	UNUSED(types);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFSIZ - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFSIZ - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/

int print_binary(va_list types, int flags, int width, int precision)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

