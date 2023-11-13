#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * c_Handling - is a function to handle characters in printf
 * @myPtr: is a pointer to the the character
 * @theArgNum: is the number of the expected arguments
 * @fp: is to determine the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to determine the location in the array
 * Return: is to return the number of characters that are printed
 */
int c_Handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp)
{
	int c = va_arg(myPtr, int);
	char c0 = '\0';

	if (theArgNum < 0)
		return (-1);
	if (*bp < 1024)
	{
		if (c < 0 || c > 127)
		{
			if (c < 0)
			{
				mb[(*bp)++] = c0;
			}
			else if (c > 127)
			{
				if (c <= 255)
					mb[(*bp)++] = c0;
				else
				{
					c %= 256;
					mb[(*bp)++] = c;
				}
			}
		}
		else
		{
			mb[(*bp)++] = c;
		}
		*fp += 2;
		return (1);
	}
	return (0);
}
