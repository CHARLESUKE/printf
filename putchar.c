#include "main.h"

/**
 * _putchar - print the characters
 *
 * @c: printed characters
 */

int _putchar(int c)
{
	return (write(1, &c, 1));
}
