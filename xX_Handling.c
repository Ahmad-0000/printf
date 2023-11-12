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
	if (x == 'X')
		return ('A' - 10);
}
/**
 * xX_Handling - is a function to handle hexadecimals
 * @myPtr: is to pull the hexadecimal
 * @theArgNum: is to determine the number of the left arguments to print
 * @theCase: is to determine wheter to apply a..f or A..F in the hexadecimal
 * Return: is to return the number of the printed characters
 */
int xX_Handling(va_list myPtr, int theArgNum, char theCase)
{
	unsigned long int i;
	int j, k;
	char a[100];

	if (theArgNum < 0)
		return (-1);
	i = va_arg(myPtr, unsigned long int);
	for (j = 0; i; j++)
	{
		a[j] = i % 16 +	theCaseFun(theCase, i % 16);
		i /= 16;
	}
	j--;
	for (k = 0; j >= 0; j--)
	{
		write(1, &a[j], 1);
		k++;
	}
	return (k);
}
