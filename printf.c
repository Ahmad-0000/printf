#include "main.h"
/**
 * _printf - is a mini printf
 * @theFormat: is a pointer to the string to be printed and handled
 * Return: is to return the number of the printed characters
 */
int _printf(const char *theFormat, ...)
{
	int fp = 0, thePchar = 0, theArgNum, tmp, bp = 0;
	va_list myPtr;
	char myBuffer[1024];

	if (theFormat == NULL)
		return (-1);
	theArgNum = argCounting(theFormat);
	va_start(myPtr, theFormat);
	while (theFormat[fp] != '\0')
	{
		NormalText(theFormat, &fp, &thePchar, myBuffer, &bp);
		tmp = thePchar;
		if (theFormat[fp] == '%')
		{
			thePchar += opDeterminer(theFormat, &theArgNum, &fp, myPtr, myBuffer, &bp);
			if (thePchar < tmp)
			{
				va_end(myPtr);
				return (-1);
			}
		}
		if (bp > 1023)
			printing(myBuffer, &bp);
	}
	printing(myBuffer, &bp);
	va_end(myPtr);
	return (thePchar);
}
