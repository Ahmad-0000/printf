#include <stdarg.h>
#include <unistd.h>
/**
 * o_Handling - is a function to handle octals
 * @myPtr: is to pull the octal
 * @theArgNum: is to determine the left arguments to be printed
 * Return: is to return the number of the written characters
 */
int o_Handling(va_list myPtr, int theArgNum)
{
	unsigned long int o;
	int i, j = 0;
	char a[100];

	if (theArgNum < 0)
		return (-1);
	o = va_arg(myPtr, unsigned long int);
	for (i = 0; o; i++)
	{
		a[i] = o % 8 + '0';
		o /= 8;
	}
	i--;
	for (; i >= 0; i--)
	{
		write(1, &a[i], 1);
		j++;
	}
	return (j);
}
