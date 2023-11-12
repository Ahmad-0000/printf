#include <stdarg.h>
#include <unistd.h>
/**
 * binaryHandling - is a function to convert an unsigned int to binary
 * @myPtr: is to pull the number
 * @theArgNum: is to determine the number of the left arguments to be printed
 * Return: is to return the number of the printed numbers
 */
int binaryHandling(va_list myPtr, int theArgNum)
{
	unsigned int theNum;
	int a[32], j = 0, i;

	if (theArgNum < 0)
		return (-1);
	theNum = va_arg(myPtr, unsigned int);
	do {
		a[j] = theNum % 2 + '0';
		theNum /= 2;
		j++;
	} while (theNum);
	j--;
	for (i = 0; j >= 0; j--)
	{
		write(1, &a[j], 1);
		i++;
	}
	return (i);
}
