#include "main.h"
/**
 * opDeterminer - is to determine the argument to print
 * @F: is the format string
 * @A: is the number of the expected arguments
 * @fp: is to locate the current position in the format string
 * @P: is to pull the next argument
 * @mb: is a 1024 array to write in
 * @bp: is to the place in the array
 * Return: is to return the number of the printed characters
 *	or -1 when there is an error
 */
int opDeterminer(const char *F, int *A, int *fp, va_list P, char *mb, int *bp)
{
	char c = F[*fp + 1];

	if (c == 'c')
		return (c_Handling(P, --(*A), fp, mb, bp));
	else if (c == 's')
		return (s_Handling(P, --(*A), fp, mb, bp));
	else if (c == '%')
		return (per_Handling(fp, mb, bp));
	else if (c == 'd' || c == 'i')
		return (id_handling(P, --(*A), fp, mb, bp));
	else if (c == 'u')
		return (u_Handling(P, --(*A), fp, mb, bp));
	else if (c == 'b')
		return (binaryHandling(P, --(*A), fp, mb, bp));
	else if (c == 'o')
		return (o_Handling(P, --(*A), fp, mb, bp));
	else if (c == 'x' || c == 'X')
		return (xX_Handling(P, --(*A), c, fp, mb, bp));
	else if (c == 'S')
		return (S_Handling(P, --(*A), fp, mb, bp));
	else if (c == 'p')
		return (pointers(P, --(*A), fp, mb, bp));
	else
		return (finally(c, fp, mb, bp));
}
