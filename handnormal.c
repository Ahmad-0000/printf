#include "main.h"
#include <stdio.h>

/**
 * handnormal - is to copy normal characters into the buffer
 * @fmt: is a pointer to a pointer to the current position in the format text
 * @wrtnchar: is a pointer to the number of the printed characters by _printf
 * @buff: a buffer to fill 
 * @bpos: is a pointer to the current index in the buffer
 */

void handnormal(const char **fmt, int *wrtnchar, char *buff, int *bpos)
{
	int adtnchars = 0; /* addition chars */
	const char *temp;

	temp = *fmt;
	for (; *temp != '%' && *temp && *bpos < BUFFER_SIZE - 1; temp++)
	{
		buff[(*bpos)++] = *temp;
		if (*bpos == BUFFER_SIZE || !(*(temp + 1)))
			_fflush(buff, bpos);
		adtnchars++;
	}
	*fmt = temp;
	*wrtnchar += adtnchars;
}
