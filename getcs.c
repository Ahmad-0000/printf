#include <stdlib.h>
#include "main.h"

/**
 * getcs - a function to get the conversion specification pattern after '%'
 * @fmt: a pointer to a pointer to the first character after '%' in the format
 *	string
 * Return: is to return an array of 6 integers with the following convention:
 *	- a[0]: conersion specifier characters
 *	- a[1]: '0' or '-' flags
 *	- a[2]: ' ' or '+' flags
 *	- a[3]: '#' flag
 *	- a[4]: field width
 *	- a[5]: precision
 *	# a 0 as a value of a[i] indicates no corresponding value, -1 is used in
 *	case of precision.
 */

conspc_t *getcs(const char **fmt)
{
	conspc_t *cs;
	int i, width, precision;
	char *conspc = "csdiuboxXSprR%";
	char *flags = "-0+ #";
	const char *temp;

	cs = malloc(sizeof(*cs));
	if (!cs)
		return (NULL);
	cs->cs = cs->fg1 = cs->fg2 = cs->fg3 = cs->width = cs->precision = 0;
	cs->len = 0;
	cs->lmod = 0;
	temp = *fmt;
	while (*temp)
	{
		for (i = 0; conspc[i]; i++)
			if (*temp == conspc[i])
			{
				cs->cs = conspc[i];
				goto flags;
			}
		temp++;
	}
flags:
	while (*(temp - 1) != '%')
		temp--;
	while (*temp)
	{
		for (i = 0; *temp != flags[i] && i < 5; i++)
			;
		if (i == 5)
			break;
		switch (*temp)
		{
			case '-':
				cs->fg1 = '-';
				break;
			case '0':
				if (!cs->fg1)
					cs->fg1 = '0';
				break;
			case '+':
				cs->fg2 = '+';
				break;
			case ' ':
				if (!cs->fg2)
					cs->fg2 = ' ';
				break;
			case '#':
				cs->fg3 = '#';
				break;
		};
		temp++;
	}
	i = 1;
	width = 0;
	while (*temp >= '0' && *temp <= '9')
	{
		width *= i;
		width += *temp - 48;
		i *= 10;
		temp++;
	}
	cs->width = width;
	precision = 0;
	i = 1;
	cs->precision = -1;
	if (*temp == '.')
	{
		temp++;
		while (*temp >= '0' && *temp <= '9')
		{
			precision *= i;
			precision += *temp - 48;
			i *= 10;
			temp++;	
		}
		cs->precision = precision;
	}
	if (*temp == 'l' || *temp == 'h')
	{
		cs->lmod = *temp;
		temp++;
	}
	temp++;
	*fmt = temp;
	return (cs);
}
