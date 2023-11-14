/**
 * theCaseFun - is a function to apply a..f or A..F in the hexadecimal
 * @x: is to choose the format
 * @xx: is to determine the reminder
 * Return: the number by which will happen to determine the digit
 */
char theCaseFun(char x, unsigned long int xx)
{
	if (xx < 10)
		return ('0');
	if (x == 'x')
		return ('a' - 10);
	else
		return ('A' - 10);
}
