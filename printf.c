#include "main.h"

int _printf(const char *theFormat, ...)
{
	int pc = 0, i = 0;
	va_list A;

	if (theFormat == NULL)
		return (-1);
	va_start(A, theFormat);
	for (; theFormat[i] ; i++)
	{
		if (theFormat[i] != '%')
		{
			write(1, &theFormat[i], 1);
			pc++;
		}
		else if (theFormat[i] == '%')
		{
			i++;
			pc += OD(theFormat[i], A);
			if (theFormat[i] == '\0')
				break;
		}
	}
	va_end(A);
	return (pc);
}
