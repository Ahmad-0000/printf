#include "main.h"
#include <stdlib.h>

/**
 * c_Handling - is a function to handle characters in printf
 * @myPtr: is a pointer to the the character
 * @theArgNum: is the number of the expected arguments
 * @fp: is to determine the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to determine the location in the array
 * Return: is to return the number of characters that are printed
 */

int handc(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	int c;

	c = va_arg(ap, int);
	conspc->len = 1;
	/* if (theArgNum < 0)
		return (-1); */
	if (*bpos + conspc->width + 1 > BUFFER_SIZE)
		_fflush(buff, bpos);
	if (conspc->fg1 == '0')
		conspc->fg1 = 0;
	handwidth(conspc, buff, bpos, (char *)&c, 0);
	free(conspc);
	return (1);
}
