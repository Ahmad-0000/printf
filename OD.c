#include "main.h"

int OD(char c, va_list A)
{
	int pc = 0, theLength;
	char *s;
	int ch;

	switch (c)
	{
		case 's' :
			s = va_arg(A, char *);
			theLength = _strlen(s);
			write(1, s, theLength);
			return (theLength);
		case 'c' :
			ch = va_arg(A, int);
			write(1, &ch, 1);
			return (++pc);
		case '%' :
			ch = '%';
			write(1, &ch, 1);
			return (++pc);
	}
	return (0);
}
