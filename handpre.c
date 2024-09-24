#include <stdlib.h>
#include "main.h"

char *handpre(conspc_t *conspc, char *val)
{
	char *newval;
	int i;

	newval = malloc(sizeof(*newval) * (conspc->precision + 1));
	if (!newval)
		return (NULL);
	i = 0;
	while (val[i] && i < conspc->precision)
	{
		newval[i] = val[i];
		i++;
	}
	newval[i] = '\0';
	conspc->len = conspc->precision;
	return (newval);
}
