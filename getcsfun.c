#include "main.h"

/**
 * getcsfun - is a function to return a function to handle a specific
 *	conversion specifier.
 * @cs: is a conversion specifier.
 * Return: is to returen the appropriate function or NULL if none
 */

int (*getcsfun(char cs))(conspc_t *conspc, char *buff, int *bpos, va_list ap)
{
	csfun_t csfun[14] = {
		{'c', handc},
		{'s', hands},
		{'%', handper},
		{'d', handd},
		{'i', handd},
		{'b', handb},
		{'u', handu},
		{'o', hando},
		{'x', handxX},
		{'X', handxX},
		{'S', handS},
		{'p', handp},
		{'r', handr},
		{'R', handR}
	};
	int i;

	for (i = 0; i < 14; i++)
	{
		if (csfun[i].cs == cs)
			return (csfun[i].fun);
	}
	return (NULL);
}
