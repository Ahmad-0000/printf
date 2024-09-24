#include "main.h"
#include <stdlib.h>

/**
 * s_Handling - is a function to handle strings in printf
 * @myPtr: is a pointer to the string
 * @theArgNum: is the number of the expected arguments
 * @fp: is to specifiy the place in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the place in the array
 * Return: is to return the length of the string
 */

int hands(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	int wrtnchar;
	int mod = FALSE; /* is the original string modified */
	char *str, *newstr;

	/*if (theArgNum < 0)1
		return (-1);*/
	str = va_arg(ap, char *);
	if (str == NULL)
		return (-1);
	newstr = str;
	conspc->len = _strlen(str);
	if ((*bpos + conspc->len + conspc->width) > BUFFER_SIZE)
		_fflush(buff, bpos);
	if (conspc->precision > -1 && conspc->len > conspc->precision)
	{
		newstr = handpre(conspc, str);
		mod = TRUE;
		if (!newstr)
			return (-1);
	}
	if (conspc->fg1 == '0')
		conspc->fg1 = 0;
	wrtnchar = handwidth(conspc, buff, bpos, newstr, 0);
	if (mod)
		free(newstr);
	free(conspc);
	return (wrtnchar);
}
