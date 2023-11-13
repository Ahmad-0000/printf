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
	int i = 0, thePchar = 0, theArgNum, tmp, b = 0;
	va_list myPtr;
	char myBuffer[1024];

	if (theFormat == NULL)
		return (-1);
	theArgNum = argCounting(theFormat);
	va_start(myPtr, theFormat);
	while (theFormat[i] != '\0' && b < 1024)
	{
		NormalText(theFormat, &i, &thePchar, myBuffer, &b);
		tmp = thePchar;
		if (theFormat[i] == '%')
		{
			thePchar += opDeterminer(theFormat, &theArgNum, &i, myPtr, myBuffer, &b);
			if (thePchar < tmp)
				return (-1);
		}
		if (b == 1024)
			printing(myBuffer, &b);
	}
	printing(myBuffer, &b);
	va_end(myPtr);
	return (thePchar);
}
