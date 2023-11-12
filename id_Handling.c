#include <stdarg.h>
#include <unistd.h>
/**
 * id_handling - is a function to handle the (i) and (d) conversion specifiers
 * @myPtr: is to pull the next argument
 * @theArgNum: is to determine the left arguments to be printed
 * Return: is to return the number of the printed characters (a digit by digit)
 *	including the minus sign
 */
int id_handling(va_list myPtr, int theArgNum)
{
	int i, theSign, j;
	char a[11];

	if (theArgNum < 0)
		return (-1);
	i = va_arg(myPtr, int);
	theSign = i < 0 ? -1 : 1;
	if (i == 0)
	{
		a[0] = '0';
		return (write(1, &a[0], 1));
	}
	i = i < 0 ? -i : i;
	for (j = 0; i; j++)
	{
		a[j] = (i % 10) + '0';
		i /= 10;
	}
	a[j] = theSign == -1 ? '-' : a[j--];
	for (i = 0; j >= 0; j--)
	{
		write(1, &a[j], 1);
		i++;
	}
	return (i);
}
