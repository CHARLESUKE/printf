#include "main.h"

/**
 * retrieve_size - Calculate the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: retrieve_size.
 */
int retrieve_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int retrieve_size = 0;

	if (format[curr_i] == 'p')
		retrieve_size = RS_LONG;
	else if (format[curr_i] == 'g')
		retrieve_size = RS_SHORT;


	if (retrieve_size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (retrieve_size);
}
