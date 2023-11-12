#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * c_Handling - is a function to handle characters in printf
 * @myPtr: is a pointer to the the character
 * Return: is to return the number of characters that are printed
 */
int c_Handling(va_list myPtr)
{
	int c = va_arg(myPtr, int);

	if (c < 0 || c > 127)
		exit(-1);
	return (write(1, &c, 1));
}
