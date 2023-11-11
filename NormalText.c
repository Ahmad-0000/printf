#include <unistd.h>
/**
 * NormalText - is to print the normal text in printf
 * @theFormat: is a pointer to the text
 * @j: is a pointer to the unprinted position
 * @thePchar: is a pointer to the number of the printed characters by _printf
 * Return: is to return a number to track the new position in the string
 */
int NormalText(const char *theFormat, int j, int *thePchar)
{
	int k = 0, i = j;

	for (; theFormat[i] != '%' && theFormat[i] != '\0'; i++)
		k++;
	*thePchar += k;
	write(1, (theFormat + j), k);
	return (i);
}
