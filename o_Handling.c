#include "main.h"
/**
 * o_Handling - is a function to handle octals
 * @myPtr: is to pull the octal
 * @theArgNum: is to determine the left arguments to be printed
 * @fp: is to specifiy the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the location in the array
 * Return: is to return the number of the written characters
 */
int o_Handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp)
{
	unsigned long int o;
	int i = 0, j = 0;
	char a[100];

	if (theArgNum < 0)
		return (-1);
	o = va_arg(myPtr, unsigned long int);
	do {
		a[i++] = o % 8 + '0';
		o /= 8;
	} while (o);
	i--;
	if ((i + 1 + *bp) > 1024)
		printing(mb, bp);
	for (; i >= 0; i--)
	{
		mb[(*bp)++] = a[i];
		j++;
	}
	*fp += 2;
	return (j);
}
