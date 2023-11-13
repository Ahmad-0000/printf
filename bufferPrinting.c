#include <unistd.h>
/**
 * printing - is to print 1024 array when it is full or the
 *	'\0' in the format string was reached
 * @theBuffer: is the array
 * @theSize: is to specifiy the size to be printed
 */
void printing(char *theBuffer, int *theSize)
{
	write(1, &theBuffer[0], *theSize);
	*theSize = 0;
}
