#include <unistd.h>
#include <stdarg.h>
/**
 * c_Handling - is a function to handle characters in printf
 * @myPtr: is a pointer to the the character
 * Return: is to return the number of characters that are printed
 */
int c_Handling(va_list myPtr)
{
	char c = va_arg(myPtr, int);

	return (write(1, &c, 1));
}
