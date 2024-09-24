#include "main.h"
#include <stdlib.h>

/**
 * o_Handling - is a function to handle octals
 * @myPtr: is to pull the octal
 * @theArgNum: is to determine the left arguments to be printed
 * @fp: is to specifiy the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the location in the array
 * Return: is to return the number of the written characters
 */
int hando(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	unsigned long int num;
	int arpos;
	int wrtnchar = 0;
	char arrep[24] = {0};

	if (conspc->lmod == 'l')
		num = va_arg(ap, long unsigned);
	else if (conspc->lmod == 'h')
		num = va_arg(ap, unsigned) % 65536;
	else
		num = va_arg(ap, unsigned);
	arpos = 0;
	do {
		arrep[arpos++] = num % 8 + '0';
		num /= 8;
	} while (num);
	arpos--;
	if ((*bpos + (conspc->width > 12 ? conspc->width : 12)) > BUFFER_SIZE)
		_fflush(buff, bpos);
	buff[*bpos] = '0';
	*bpos += 1;
	wrtnchar += 1;
	conspc->len++;
	conspc->len += _strlen(arrep);
	wrtnchar += handwidth(conspc, buff, bpos, arrep, arpos);
	free(conspc);
	return (wrtnchar);
}
