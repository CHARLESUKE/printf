#include "main.h"
#include <ctype.h>

/**
 * fetch_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: fetch_precision or -1 if not specified.
 */
int fetch_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int fetch_precision = -1;

	if (format[curr_i] != '.')
		return (fetch_precision);

	fetch_precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (isdigit(format[curr_i]))
		{
			fetch_precision *= 10;
			fetch_precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			fetch_precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;
	return (fetch_precision);
}
