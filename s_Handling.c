#include "main.h"
/**
 * s_Handling - is a function to handle strings in printf
 * @myPtr: is a pointer to the string
 * @theArgNum: is the number of the expected arguments
 * @fp: is to specifiy the place in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the place in the array
 * Return: is to return the length of the string
 */
int s_Handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp)
{
	int i = 0, theLength;
	char *c;

	if (theArgNum < 0)
		return (-1);
	if (*bp < 1024)
	{
		c = va_arg(myPtr, char *);
		if (c == NULL)
		{
			(*fp) += 2;
			return (-1);
		}
		theLength = _strlen(c);
		if ((*bp + theLength) > 1024)
			printing(mb, bp);
		while (c[i] != '\0')
			mb[(*bp)++] = c[i++];
		(*fp) += 2;
		return (i);
	}
	return (0);
}
