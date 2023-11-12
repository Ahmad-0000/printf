#include <stdarg.h>
#include <unistd.h>
/**
 * u_Handling - is a function to handle the unsigned integers
 * @myPtr: is to pull the unsigned interger
 * @theArgNum: is to determine the left expected arguments
 * Return: is to return the number of the printed characters
 */
int u_Handling(va_list myPtr, int theArgNum)
{
	unsigned int u;
	int r = 0, i;
	char a[10];

	if (theArgNum < 0)
		return (-1);
	u = va_arg(myPtr, unsigned int);
	for (i = 0; u; i++)
	{
		a[i] = u % 10 + '0';
		u /= 10;
	}
	i--;
	for (; i >= 0; i--)
	{
		write(1, &a[i], 1);
		r++;
	}
	return (r);
}
