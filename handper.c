#include "main.h"
#include <stdlib.h>

/**
 * per_Handling - is to handle %%
 * @fp: is to specifiy the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the location in the buffer
 * Return: is to return 1 when writing, or 0 when not
 */

int handper(conspc_t *conspc, char *buff, int *bpos, va_list __attribute__((unused))ap)
{
	if (*bpos >= BUFFER_SIZE)
		return (0);
	buff[(*bpos)++] = '%';
	free(conspc);
	return (1);
}
