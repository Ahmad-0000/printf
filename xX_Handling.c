#include "main.h"
/**
 * xX_Handling - is a function to handle hexadecimals
 * @myPtr: is to pull the hexadecimal
 * @A: is to determine the number of the left arguments to print
 * @C: is to determine wheter to apply a..f or A..F in the hexadecimal
 * @fp: is to specifiy the place in the format string
 * @mb: it's a 1024 array to write in
 * @bp: to determine the place in the array
 * Return: is to return the number of the printed characters
 */
int xX_Handling(va_list myPtr, int A, char C, int *fp, char *mb, int *bp)
{
	unsigned long int i;
	int j = 0, k = 0;
	char a[100];

	if (A < 0)
		return (-1);
	i = va_arg(myPtr, unsigned long int);
	do {
		a[j++] = i % 16 + theCaseFun(C, i % 16);
		i /= 16;
	} while (i);
	j--;
	if ((j + 1 + *bp) > 1024)
		printing(mb, bp);
	for (; j >= 0; j--)
	{
		mb[(*bp)++] = a[j];
		k++;
	}
	*fp += 2;
	return (k);
}
