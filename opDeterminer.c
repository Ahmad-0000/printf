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
	char c = theFormat[i + 1];

	if (c == 'c')
		return (c_Handling(myPtr, --(*theArgNum)));
	else if (c == 's')
		return (s_Handling(myPtr, --(*theArgNum)));
	else if (c == '%')
		return (write(1, &theFormat[i + 1], 1));
	else if (c == 'd' || c == 'i')
		return (id_handling(myPtr, --(*theArgNum)));
	else if (c == 'u')
		return (u_Handling(myPtr, --(*theArgNum)));
	else if (c == 'b')
		return (binaryHandling(myPtr, --(*theArgNum)));
	else if (c == 'o')
		return (o_Handling(myPtr, --(*theArgNum)));
	else if (c == 'x' || c == 'X')
		return (xX_Handling(myPtr, --(*theArgNum), c));
	else
		return (-1);
}
