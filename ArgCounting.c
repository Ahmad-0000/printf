/**
 * argCounting - is count the arguments number that is expected
 * @theFormat: is a pointer to the string
 * Return: is to return the number of the arguments
 */
int argCounting(const char *theFormat)
{
	int i = 0, theArgNum = 0;

	while (theFormat[i] != '\0')
	{
		if (theFormat[i] == '%' && theFormat[i + 1] != '%')
		{
			theArgNum++;
			i++;
		}
		else if (theFormat[i] == '%' && theFormat[i + 1] == '%')
		{
			i += 2;
		}
		else
		{
			i++;
		}
	}
	return (theArgNum);
}
