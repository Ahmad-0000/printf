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
	int i = 0, j = 0, thePchar = 0, theArgNum, tmp;
	va_list myPtr;

	if (theFormat == NULL)
		return (-1);
	theArgNum = argCounting(theFormat);
	va_start(myPtr, theFormat);
	while (theFormat[i] != '\0')
	{
		i = NormalText(theFormat, j, &thePchar);
		tmp = thePchar;
		if (theFormat[i] == '%')
		{
			thePchar += opDeterminer(theFormat, &theArgNum, i, myPtr);
			if (thePchar < tmp)
				return (-1);
			j = i += 2;
		}
	}
	va_end(myPtr);
	return (thePchar);
}
