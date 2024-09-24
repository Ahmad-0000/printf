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

int handr(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	int wrtnchar, i, j;
	char *str, *newstr;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (-1);
	conspc->len = _strlen(str);
	if ((*bpos + conspc->len + conspc->width) > BUFFER_SIZE)
		_fflush(buff, bpos);
	newstr = malloc(sizeof(*newstr) * (conspc->len + 1));
	if (!newstr)
		return (-1);
	i = j = 0;
	while (str[i])
		i++;
	newstr[i] = '\0';
	i--;
	while (i >= 0)
	{
		newstr[j] = str[i];
		j++;
		i--;
	}
	if (conspc->fg1 == '0')
		conspc->fg1 = 0;
	wrtnchar = handwidth(conspc, buff, bpos, newstr, 0);
	free(newstr);
	free(conspc);
	return (wrtnchar);
}
