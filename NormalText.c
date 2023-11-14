#include "main.h"
/**
 * NormalText - is to print the normal text in printf
 * @F: is a pointer to the text
 * @fp: is a pointer to the place in F
 * @pc: is a pointer to the number of the printed characters by _printf
 * @mb: is a 1024 array to write
 * @bp: is to locate the place in the array
 * Return: is to return a number to track the new position in the string
 */
void NormalText(const char *F, int *fp, int *pc, char *mb, int *bp)
{
	int k = 0;

	for (*fp = *fp; F[*fp] != '%' && F[*fp] != '\0' && *bp < 1024; (*fp)++)
	{
		mb[(*bp)++] = F[*fp];
		if (*bp == 1024 && F[*fp + 1] != '\0' && F[*fp + 1] != '%')
			printing(mb, bp);
		k++;
	}
	*pc += k;
}
