#include "main.h"
/**
 * theConverter - is to convert the nonprintable character
 * @mb: is the buffer
 * @bp: is to determine the current location in the buffer
 * @c: is the nonprintable character
 */
void theConverter(char *mb, int *bp, char c)
{
	char a[] = "0123456789ABCDEF";

	mb[(*bp)++] = '\\';
	mb[(*bp)++] = 'x';
	if (c < 15)
	{
		mb[(*bp)++] = '0';
		mb[(*bp)++] = a[(int)c];
	}
	else
	{
		mb[(*bp)++] = c % 16 + '0';
		c /= 16;
		mb[(*bp)++] = a[(int)c];
	}
}
/**
 * S_Handling - is a function to handle the special S conversion specifier
 *	to print nonprintable characters in the a string in the form (\x)
 *	that is followed in by the hexadecimal value of the character in
 *	Upper case, and in 2 digits
 * @myPtr: is to pull the argument
 * @A: is to determine the number of the left format specifier
 * @fp: is the current location in the format string
 * @mb: is the buffer
 * @bp: is the current location in the buffer
 * Return: is to return the number of the printed characters
 */
int S_Handling(va_list myPtr, int A, int *fp, char *mb, int *bp)
{
	char *s;
	int i = 0, pc = 0;

	if (A < 0)
		return (-1);
	s = va_arg(myPtr, char *);
	if (s == NULL)
		return (-1);
	printing(mb, bp);
	for (; s[i] != '\0'; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || (s[i] >= 127))
		{
			theConverter(mb, bp, s[i]);
			pc += 4;
		}
		else
		{
			mb[(*bp)++] = s[i];
			pc++;
		}
	}
	*fp += 2;
	return (pc);
}
