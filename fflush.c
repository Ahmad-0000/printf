#include "main.h"

/**
 * _fflush - is a function to write a buffer into the stdout
 * @buff: is the buffer
 * @n: is the number of characters to print from the buffer
 */

void _fflush(char *buff, int *n)
{
	write(1, &buff[0], *n);
	*n = 0;
}
