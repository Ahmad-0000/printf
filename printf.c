#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - is a mini printf
 * @theFormat: is a pointer to the string to be printed and handled
 * Return: is to return the number of the printed characters
 */
int _printf(const char *theFormat, ...)
{
	int i = 0, j = 0, thePchar = 0;
	va_list myPtr;

	if (theFormat == NULL)
		exit(-1);
	va_start(myPtr, theFormat);
	while (theFormat[i] != '\0')
	{
		i = NormalText(theFormat, j, &thePchar);
		if (theFormat[i] == '%')
		{
			if (theFormat[i + 1] == 'c')
			{
				thePchar += c_Handling(myPtr);
				j = i += 2;
			}
			else if (theFormat[i + 1] == 's')
			{
				thePchar += s_Handling(myPtr);
				j = i += 2;
			}
			else if (theFormat[i + 1] == '%')
			{
				thePchar += write(1, &theFormat[i + 1], 1);
				j = i += 2;
			}
			else
			{
				exit(-1);
			}
		}
	}
	va_end(myPtr);
	return (thePchar);
}
