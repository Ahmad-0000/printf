/**
 * per_Handling - is to handle %%
 * @fp: is to specifiy the location in the format string
 * @mb: is a 1024 array to write in
 * @bp: is to specifiy the location in the buffer
 * Return: is to return 1 when writing, or 0 when not
 */
int per_Handling(int *fp, char *mb, int *bp)
{
	if (*bp >= 1024)
		return (0);
	mb[(*bp)++] = '%';
	*fp += 2;
	return (1);
}
