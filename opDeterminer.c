#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * opDeterminer - is to determine the argument to print
 * @theFormat: is the format string
 * @theArgNum: is the number of the expected arguments
 * @i: is to locate the current position in the format string
 * @myPtr: is to pull the next argument
 * Return: is to return the number of the printed characters
 *	or -1 when there is an error
 */
int opDeterminer(const char *theFormat, int *theArgNum, int i, va_list myPtr)
{
	if (theFormat[i + 1] == 'c')
		return (c_Handling(myPtr, --(*theArgNum)));
	else if (theFormat[i + 1] == 's')
		return (s_Handling(myPtr, --(*theArgNum)));
	else if (theFormat[i + 1] == '%')
		return (write(1, &theFormat[i + 1], 1));
	else if (theFormat[i + 1] == 'd' || theFormat[i + 1] == 'i')
		return (id_handling(myPtr, --(*theArgNum)));
	else if (theFormat[i + 1] == 'b')
		return (binaryHandling(myPtr, --(*theArgNum)));
	else
		return (-1);
}
