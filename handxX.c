#include "main.h"
#include <stdlib.h>

/**
 * xX_Handling - is a function to handle hexadecimals
 * @myPtr: is to pull the hexadecimal
 * @A: is to determine the number of the left arguments to print
 * @C: is to determine wheter to apply a..f or A..F in the hexadecimal
 * @fp: is to specifiy the place in the format string
 * @mb: it's a 1024 array to write in
 * @bp: to determine the place in the array
 * Return: is to return the number of the printed characters
 */


int handxX(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	long unsigned num;
	int arpos;
	int wrtnchar;
	char arrep[20] = {0};

	arpos = 0;
	if (conspc->lmod == 'l')
		num = va_arg(ap, long unsigned);
	else if (conspc->lmod == 'h')
		num = va_arg(ap, unsigned) % 65536;
	else
		num = va_arg(ap, unsigned);
	if (!num)
		conspc->fg3 = 0;
	do {
		arrep[arpos++] = num % 16 + xorX(conspc->cs, num % 16);
		num /= 16;
	} while (num);
	arpos--;
	if ((*bpos + (conspc->width > 10 ? conspc->width : 10)) > BUFFER_SIZE)
		_fflush(buff, bpos);
	buff[*bpos] = '0';
	*bpos += 1;
	buff[*bpos] = 'x';
	*bpos += 1;
	wrtnchar = 2;
	conspc->len += _strlen(arrep) + 2;
	wrtnchar += handwidth(conspc, buff, bpos, arrep, arpos);
	free(conspc);
	return (wrtnchar);
}
/**
 * theCaseFun - is a function to apply a..f or A..F in the hexadecimal
 * @x: is to choose the format
 * @xx: is to determine the reminder
 * Return: the number by which will happen to determine the digit
 */

char xorX(char x, unsigned int remainder)
{
	if (remainder < 10)
		return ('0');
	if (x == 'x')
		return ('a' - 10);
	else
		return ('A' - 10);
}
