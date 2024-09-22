#include "main.h"

/**
 * _printf - is a mini printf
 * @fmt: is a pointer to the string to be printed and handled
 * Return: is to return the number of the printed characters
 */

int _printf(const char *fmt, ...)
{
	int fpos = 0, wrtnchar = 0, argnum, tmp, bpos = 0;
	va_list ap;
	char buf[1024];

	if (fmt == NULL)
		return (-1);
	argnum = argCounting(fmt);
	va_start(ap, fmt);
	while (fmt[fpos] != '\0')
	{
		NormalText(fmt, &fpos, &wrtnchar, buf, &bpos);
		tmp = wrtnchar;
		if (fmt[fpos] == '%')
		{
			wrtnchar += opDeterminer(fmt, &argnum, &fpos, ap, buf, &bpos);
			if (wrtnchar < tmp)
			{
				va_end(ap);
				return (-1);
			}
		}
		if (bpos > 1023)
			printing(buf, &bpos);
	}
	printing(buf, &bpos);
	va_end(ap);
	return (wrtnchar);
}
