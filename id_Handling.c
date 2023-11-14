#include "main.h"
/**
 * id_handling - is a function to handle the (i) and (d) conversion specifiers
 * @myPtr: is to pull the next argument
 * @theArgNum: is to determine the left arguments to be printed
 * @fp: is a pointer to specifiy the current place in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to locate the place in the array
 * Return: is to return the number of the printed characters (a digit by digit)
 *	including the minus sign
 */
int id_handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp)
{
	int i, theSign, j = 0, theLength;
	char a[15];

	if (theArgNum < 0)
		return (-1);
	i = va_arg(myPtr, int);
	theSign = i < 0 ? -1 : 1;
	i = i < 0 ? -i : i;
	do {
		a[j++] = (i % 10) + '0';
		i /= 10;
	} while (i);
	a[j] = theSign == -1 ? '-' : a[j];
	if (theSign != -1)
		j--;
	theLength = _strlen(a);
	if ((theLength + *bp) > 1024)
		printing(mb, bp);
	for (i = 0; j >= 0; j--)
	{
		mb[(*bp)++] = a[j];
		i++;
	}
	*fp += 2;
	return (i);
}
