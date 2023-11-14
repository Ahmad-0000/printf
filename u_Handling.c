#include "main.h"
/**
 * u_Handling - is a function to handle the unsigned integers
 * @myPtr: is to pull the unsigned interger
 * @theArgNum: is to determine the left expected arguments
 * @fp: is to determine the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is the location in the array
 * Return: is to return the number of the printed characters
 */
int u_Handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp)
{
	unsigned int u;
	int r = 0, i = 0;
	char a[15];

	if (theArgNum < 0)
		return (-1);
	u = va_arg(myPtr, unsigned int);
	do {
		a[i++] = u % 10 + '0';
		u /= 10;
	} while (u);
	i--;
	if ((i + 1 + *bp) > 1024)
		printing(mb, bp);
	for (; i >= 0; i--)
	{
		mb[(*bp)++] = a[i];
		r++;
	}
	*fp += 2;
	return (r);
}
