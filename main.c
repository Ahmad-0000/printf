#include <stdio.h>
#include "main.h"

int main(void)
{
	char *c = "text";
	int a = 500;

	printf("this is a %s, and this is %d a number\n", c, a);
	_printf("this is a %s, and this is %d a number\n", c, a);
	return 0;
}
