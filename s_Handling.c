#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * s_Handling - is a function to handle strings in printf
 * @myPtr: is a pointer to the string
 * Return: is to return the length of the string
 */
int s_Handling(va_list myPtr)
{
	int i = 0;
	char *c = va_arg(myPtr, char *);
	char *s = "(null)";

	if (c == NULL)
	{
		write(1, &s[0], 6);
		return (6);
	}
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}
