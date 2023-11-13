#include <unistd.h>
/**
 * NormalText - is to print the normal text in printf
 * @F: is a pointer to the text
 * @f: is a pointer to the place in F
 * @p: is a pointer to the number of the printed characters by _printf
 * @mb: is a 1024 array to write
 * @b: is to locate the place in the array
 * Return: is to return a number to track the new position in the string
 */
void NormalText(const char *F, int *f, int *p, char *mb, int *b)
{
	int k = 0;

	for (*f = *f; F[*f] != '%' && F[*f] != '\0' && *b < 1024; (*f)++)
	{
		mb[(*b)++] = F[*f];
		k++;
	}
	*p += k;
}
