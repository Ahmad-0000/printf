#include "main.h"
#include <stdio.h>

/**
 * _printf - is a mini printf
 * @fmt: is a pointer to the string to be printed and handled
 * Return: is to return the number of the printed characters
 */

int _printf(const char *fmt, ...)
{
	int wrtnchar = 0, tmp, bpos = 0;
	va_list ap;
	char buff[BUFFER_SIZE];
	conspc_t *conspc; /* conversion specification */
	int (*csfun)(conspc_t *conspc, char *buff, int *bpos, va_list ap);

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		handnormal(&fmt, &wrtnchar, buff, &bpos);
		tmp = wrtnchar;
		if (*fmt == '%')
		{
			fmt++;
			conspc = getcs(&fmt);
			csfun = getcsfun(conspc->cs);
			if (csfun)
			{
				wrtnchar += csfun(conspc, buff, &bpos, ap);
				if (wrtnchar < tmp)
				{
					va_end(ap);
					return (-1);
				}
			}
		}
		if (bpos > BUFFER_SIZE - 1)
			_fflush(buff, &bpos);
	}
	_fflush(buff, &bpos);
	va_end(ap);
	return (wrtnchar);
}
