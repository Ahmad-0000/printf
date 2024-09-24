#include "main.h"
#include <stdlib.h>

/**
 * pointers - is a function to handle the (p) format specifier
 * @myPtr: is to pull the pointer
 * @A: is to determine the number of the left arguments
 * @fp: is to determine the location in the format string
 * @mb: is a buffer
 * @bp: is to determine the location in the buffer
 * Return: is to return the number of the written characters
 */

int handp(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	unsigned long int p;
	int wrtnchar;
       	int arpos;
	char arrep[20] = {0};

	p = va_arg(ap, unsigned long int);
	if (p == 0)
	{
		if ((*bpos + 5) > BUFFER_SIZE)
			_fflush(buff, bpos);
		buff[(*bpos)++] = '(';
		buff[(*bpos)++] = 'n';
		buff[(*bpos)++] = 'i';
		buff[(*bpos)++] = 'l';
		buff[(*bpos)++] = ')';
		return (5);
	}
	if ((*bpos + 19 + conspc->width) > BUFFER_SIZE)
		_fflush(buff, bpos);
	arpos = 0;
	do {
		arrep[arpos++] = p % 16 + xorX('x', p % 16);
		p /= 16;
	} while (p);
	arpos--;
	buff[(*bpos)++] = '0';
	buff[(*bpos)++] = 'x';
	wrtnchar = 2;
	conspc->len = _strlen(arrep) + 2;
	wrtnchar += handwidth(conspc, buff, bpos, arrep, arpos);
	free(conspc);
	return (wrtnchar);
}
