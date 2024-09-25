#include "main.h"
#include <stdlib.h>

/**
 * S_Handling - is a function to handle the special S conversion specifier
 *	to print nonprintable characters in the a string in the form (\x)
 *	that is followed in by the hexadecimal value of the character in
 *	Upper case, and in 2 digits
 * @myPtr: is to pull the argument
 * @A: is to determine the number of the left format specifier
 * @fp: is the current location in the format string
 * @mb: is the buffer
 * @bp: is the current location in the buffer
 * Return: is to return the number of the printed characters
 */

int handS(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	char *str, *newstr;
	int hex;
	int i, j;
	int wrtnchar;
	int mod = FALSE;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (-1);
	conspc->len = _strlen(str);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
			conspc->len += 3;
		i++;
	}
	newstr = str;
	if (conspc->len > _strlen(str))
	{
		mod = TRUE;
		newstr = malloc(sizeof(*newstr) * (conspc->len + 1));
		if (!newstr)
			return (-1);
		i = j = 0;
		while (str[i])
		{
			if (str[i] < 32 || str[i] >= 127)
			{
				hex = str[i];
				newstr[j++] = '\\';
				newstr[j++] = 'x';
				if (hex <= 15)
				{
					newstr[j++] = '0';
					newstr[j++] = hex % 16 + xorX('X', hex % 16);
				}
				else
				{
					newstr[j + 1] = hex % 16 + xorX('X', hex % 16);
					hex /= 16;
					newstr[j] = hex % 16 + xorX('X', hex % 16);
					j += 2;
				}
			}
			else
			{
				newstr[j] = str[i];
				j++;
			}
			i++;
		}
		newstr[j] = '\0';
	}
	if ((*bpos + conspc->len + conspc->width) > BUFFER_SIZE)
		_fflush(buff, bpos);
	if (conspc->fg1 == '0')
		conspc->fg1 = 0;
	wrtnchar = handwidth(conspc, buff, bpos, newstr, 0);
	if (mod)
		free(newstr);
	free(conspc);
	return (wrtnchar);
}
