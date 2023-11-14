#include "main.h"
/**
 * pointers - is a function to handle the (p) format specifier
 * @myPtr: is to pull the pointer
 * @A: is to determine the number of the left arguments
 * @fp: is to determine the location in the format string
 * @mb: is a buffer
 * @bp: is to determine the location in the buffer
 * Return: is to return the number of the written characters
 */
int pointers(va_list myPtr, int A, int *fp, char *mb, int *bp)
{
	unsigned long int p;
	int i, k = 0;
	char a[20];

	if (A < 0)
		return (-1);
	p = va_arg(myPtr, unsigned long int);
	if (p == 0)
	{
		if ((*bp + 5) > 1024)
			printing(mb, bp);
		mb[(*bp)++] = '(';
		mb[(*bp)++] = 'n';
		mb[(*bp)++] = 'i';
		mb[(*bp)++] = 'l';
		mb[(*bp)++] = ')';
		*fp += 2;
		return (5);
	}
	mb[(*bp)++] = '0';
	mb[(*bp)++] = 'x';
	do {
		a[k++] = p % 16 + theCaseFun('x', p % 16);
		p /= 16;
	} while (p);
	k--;
	if ((k + *bp + 1) > 1024)
		printing(mb, bp);
	for (i = 2; k >= 0; k--)
	{
		mb[(*bp)++] = a[k];
		i++;
	}
	*fp += 2;
	return (i);
}
