#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * s_Handling - is a function to handle strings in printf
 * @myPtr: is a pointer to the string
 * @theArgNum: is the number of the expected arguments
 * @fp: is to specifiy the place in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the place in the array
 * Return: is to return the length of the string
 */
int s_Handling(va_list myPtr, int theArgNum, int *fp, char *mb, int *bp)
{
	int i = 0;
	char *c = va_arg(myPtr, char *);
	char *s = "(null)";

	if (theArgNum < 0)
		return (-1);
	if (*bp < 1024)
	{
		if (c == NULL)
		{
			while (s[i] != '\0')
				mb[*(bp)++] = s[i++];
			(*fp) += 2;
			return (6);
		}
		while (c[i] != '\0')
			mb[(*bp)++] = c[i++];
		(*fp) += 2;
		return (i);
	}
	return (0);
}
