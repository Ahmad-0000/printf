#include <stdarg.h>
#include <unistd.h>
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
	int i, theSign, j;
	char a[11];

	if (theArgNum < 0)
		return (-1);
	if (*bp >= 1024)
		return (0);
	i = va_arg(myPtr, int);
	theSign = i < 0 ? -1 : 1;
	if (i == 0)
	{
		mb[(*bp)++] = '0';
		*fp += 2;
		return (1);
	}
	i = i < 0 ? -i : i;
	for (j = 0; i; j++)
	{
		a[j] = (i % 10) + '0';
		i /= 10;
	}
	a[j] = theSign == -1 ? '-' : a[j];
	if (theSign != -1)
		j--;
	for (i = 0; j >= 0 && *bp < 1024; j--)
	{
		mb[(*bp)++] = a[j];
		i++;
	}
	*fp += 2;
	return (i);
}
