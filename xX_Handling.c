#include <stdarg.h>
#include <unistd.h>
/**
 * theCaseFun - is a function to apply a..f or A..F in the hexadecimal
 * @x: is to choose the format
 * @xx: is to determine the reminder
 * Return: the number by which will happen to determine the digit
 */
char theCaseFun(char x, unsigned long int xx)
{
	if (xx < 10)
		return ('0');
	if (x == 'x')
		return ('a' - 10);
	else
		return ('A' - 10);
}
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
	if (*bp >= 1024)
		return (0);
	i = va_arg(myPtr, unsigned long int);
	do {
		a[j++] = i % 16 + theCaseFun(C, i % 16);
		i /= 16;
	} while (i);
	j--;
	for (; j >= 0 && *bp < 1024; j--)
	{
		mb[(*bp)++] = a[j];
		k++;
	}
	*fp += 2;
	return (k);
}
