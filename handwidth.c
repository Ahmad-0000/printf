#include "main.h"

int handpsh(conspc_t *conspc, int *bpos, char *arrep, int *arpos)
{
	char cs;

	cs = conspc->cs;
	if (cs == 'p' && !conspc->fg1)
	{
		*bpos -= 2;
		arrep[++(*arpos)] = 'x';
		arrep[++(*arpos)] = '0';
		return (-2);
	}
	if ((cs == 'd' || cs == 'i') && conspc->fg2 && !conspc->fg1)
	{
		arrep[++(*arpos)] = conspc->fg2;
		*bpos -= 1;
	}
	if (conspc->fg3)
	{
		if (cs == 'o' && !conspc->fg1)
		{
			arrep[++(*arpos)] = '0';
			*bpos -= 1;
			return (-1);
		}
		else if ((cs == 'x' || cs == 'X') && !conspc->fg1)
		{
			arrep[++(*arpos)] = cs;
			arrep[++(*arpos)] = '0';
			*bpos -= 2;
			return (-2);
		}
	}
	else
	{
		if (cs == 'o')
		{
			*bpos -= 1;
			conspc->len--;
		}
		else if (cs == 'x' || cs == 'X')
		{
			*bpos -= 2;
			conspc->len -= 2;
		}
	}
	return (0);
}

int handwidth(conspc_t *conspc, char *buff, int *bpos, char *arrep, int arpos)
{
	int wrtnchar = 0;
	char cs = conspc->cs;

	wrtnchar = handpsh(conspc, bpos, arrep, &arpos);
	while (conspc->width > conspc->len)
	{
		if (conspc->fg1 == '0')
			buff[(*bpos)++] = '0';
		else if (!conspc->fg1)
			buff[(*bpos)++] = ' ';
		else
			break;
		wrtnchar++;
		conspc->width--;
	}
	if (cs == 's' || cs == 'S' || cs == 'r' || cs == 'R')
		for (; arrep[arpos]; arpos++, wrtnchar++)
			buff[(*bpos)++] = arrep[arpos];
	else
		for (; arpos >= 0; arpos--, wrtnchar++)
			buff[(*bpos)++] = arrep[arpos];
	while (conspc->width > conspc->len)
	{
		buff[(*bpos)++] = ' ';
		wrtnchar++;
		conspc->width--;
	}
	return (wrtnchar);
}
