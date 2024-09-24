#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * u_Handling - is a function to handle the unsigned integers
 * @myPtr: is to pull the unsigned interger
 * @theArgNum: is to determine the left expected arguments
 * @fp: is to determine the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is the location in the array
 * Return: is to return the number of the printed characters
 */
int handu(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	unsigned long num;
	int wrtnchar;
	int arpos;
	char arrep[22] = {0};

	if (conspc->lmod == 'l')
		num = va_arg(ap, long unsigned);
	else if (conspc->lmod == 'h')
		num = va_arg(ap, unsigned) % 65536;
	else
		num = va_arg(ap, unsigned);
	arpos = 0;
	do {
		arrep[arpos++] = num % 10 + '0';
		num /= 10;
	} while (num);
	arpos--;
	conspc->len += _strlen(arrep);
	if (*bpos + (conspc->width > 10 ? conspc->width : 10) > BUFFER_SIZE)
		_fflush(buff, bpos);
	wrtnchar = 0;
	wrtnchar += handwidth(conspc, buff, bpos, arrep, arpos);
	free(conspc);
	return (wrtnchar);
}
