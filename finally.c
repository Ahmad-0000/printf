#include "main.h"
/**
 * finally - is to handle unknown specifiers
 * @c: is the unkonwn conversion spcifier
 * @fp: is to determine the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the location in the array
 * Return: is to return 0 when the buffer is full,
 * or the number of the written characters
 */
int finally(char c, int *fp, char *mb, int *bp)
{
	if ((*bp + 2) > 1024)
		printing(mb, bp);
	mb[(*bp)++] = '%';
	mb[(*bp)++] = c;
	*fp += 2;
	return (2);
}
