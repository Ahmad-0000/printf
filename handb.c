#include "main.h"
#include <stdlib.h>

/**
 * binaryHandling - is a function to convert an unsigned int to binary
 * @myPtr: is to pull the number
 * @theArgNum: is to determine the number of the left arguments to be printed
 * @fp: is to determine the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the place in the array
 * Return: is to return the number of the printed numbers
 */

int handb(conspc_t __attribute__((unused))*conspc, char *buff, int *bpos, va_list ap)
{
	unsigned int num;
	int arrep[32];
	int wrtnchar;
	int arpos;

	/* if (theArgNum < 0)
		return (-1); */
	arpos = 0;
	num = va_arg(ap, unsigned int);
	do {
		arrep[arpos++] = num % 2 + '0';
		num /= 2;
	} while (num);
	arpos--;
	if (*bpos + 32 > 1024)
		_fflush(buff, bpos);
	for (wrtnchar = 0; arpos >= 0; arpos--)
	{
		buff[(*bpos)++] = arrep[arpos];
		wrtnchar++;
	}
	free(conspc);
	return (wrtnchar);
}
