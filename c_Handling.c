#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * c_Handling - is a function to handle characters in printf
 * @myPtr: is a pointer to the the character
 * @theArgNum: is the number of the expected arguments
 * Return: is to return the number of characters that are printed
 */
int c_Handling(va_list myPtr, int theArgNum)
{
	int c = va_arg(myPtr, int);
	char c0 = '\0';

	if (theArgNum < 0)
		return (-1);
	if (c < 0 || c > 127)
	{
		if (c < 0)
		{
			write(1, &c0, 1);
		}
		else if (c > 127)
		{
			if (c <= 255)
				write(1, &c0, 1);
			else
			{
				c %= 256;
				write(1, &c, 1);
			}
		}
	}
	else
	{
		write(1, &c, 1);
	}
	return (1);
}
