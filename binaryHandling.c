#include <stdarg.h>
#include <unistd.h>
/**
 * binaryHandling - is a function to convert an unsigned int to binary
 * @myPtr: is to pull the number
 * @theArgNum: is to determine the number of the left arguments to be printed
 * @fp: is to determine the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the place in the array
 * Return: is to return the number of the printed numbers
 */
int binaryHandling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp)
{
	unsigned int theNum;
	int a[32], j = 0, i;

	if (theArgNum < 0)
		return (-1);
	if (*bp >= 1024)
		return (0);
	theNum = va_arg(myPtr, unsigned int);
	do {
		a[j++] = theNum % 2 + '0';
		theNum /= 2;
	} while (theNum);
	j--;
	for (i = 0; j >= 0 && *bp < 1024; j--)
	{
		mb[(*bp)++] = a[j];
		i++;
	}
	*fp += 2;
	return (i);
}
