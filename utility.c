#include "main.h"
/**
 * is_printable - Evaluates if it can print char
 * @c: Char to be evaluated.
 * Return: 1 if c is printable, esle return to 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to the buffer
 *  @ascii_code: ASSCI CODE.
 * @buffer: Array of chars.
 * @i: Index where to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a char is a digit
 * @c: evaluate char
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number specified size
 * @size: Number that indicate the type to be casted.
 * @num: Number to be casted.
 * Return: Casted value of num
 */

long int convert_size_num(long int num, int size)
{
	if (size == RS_LONG)
		return (num);
	else if (size == RS_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts number to the specified size
 * @size: The Number indicating type that are to be casted
 * @num: The Number to be casted
 * Return: Casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == RS_LONG)
		return (num);
	else if (size == RS_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

