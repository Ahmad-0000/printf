#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * id_handling - is a function to handle the (i) and (d) conversion specifiers
 * @myPtr: is to pull the next argument
 * @theArgNum: is to determine the left arguments to be printed
 * @fp: is a pointer to specifiy the current place in the format string
 * @mb: is a 1024 array to write in
 * @bpos: is to locate the place in the array
 * Return: is to return the number of the printed characters (a digit by digit)
 *	including the minus sign
 */

int handd(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	int wrtnchar;
	long num;
	int neg; /* negative */
	int arpos; /* array position */
	char arrep[22] = {0}; /* array representation */

	if (conspc->lmod == 'l')
	{
		num = va_arg(ap, long);
	}
	else if (conspc->lmod == 'h')
	{
		num = va_arg(ap, unsigned) % 65536;
		if (num == 65535)
			num = -1;
	}
	else
	{
		num = va_arg(ap, int);
	}
	neg = num < 0 ? TRUE : FALSE;
	num = num < 0 ? -num : num;
	arpos = 0;
	do {
		arrep[arpos++] = (num % 10) + '0';
		num /= 10;
	} while (num);
	arpos--;
	if ((*bpos + (conspc->width > 22 ? conspc->width: 22)) > BUFFER_SIZE)
		_fflush(buff, bpos);
	if (neg)
	{
		buff[(*bpos)++] = '-';
		conspc->fg2 = '-';
		conspc->len++;
	}
	else if (conspc->fg2)
	{
		buff[(*bpos)++] = conspc->fg2;
		conspc->len++;
	}
	conspc->len += _strlen(arrep);
	wrtnchar = 0;
	wrtnchar += handwidth(conspc, buff, bpos, arrep, arpos);
	free(conspc);
	return (wrtnchar);
}
