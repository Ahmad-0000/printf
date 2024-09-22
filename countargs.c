/**
 * countargs - is count the arguments number that is expected
 * @fmt: is a pointer to the string
 * Return: is to return the number of the arguments
 */
int countargs(const char *fmt)
{
	int i = 0;
	int argnum = 0;

	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			if (fmt[i + 1] == 'r' || fmt[i + 1] == 'R')
			{
				i++;
				continue;
			}
			argnum++;
			i++;
		}
		else if (fmt[i] == '%' && fmt[i + 1] == '%')
		{
			i += 2;
		}
		else
		{
			i++;
		}
	}
	return (argnum);
}
