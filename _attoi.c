#include "shell.h"

/**
 * interactive - it will return if shell works
 * @info: the address of the sruct
 *
 * Return: must re 1 if works or 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - it will check if char is a del
 * @j: the car to be checked
 * @del: del str
 * Return: 1 if t and 0 if other
 */
int is_delim(char j, char *del)
{
	while (*del)
		if (*del++ == j)
			return (1);
	return (0);
}
/**
 * _isalpha - looks if every is in alpha
 * @j: char to insert
 * Return: 1 if j is alphabetic
 */
int _isalpha(int j)
{
	if ((j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - it will conv str to int
 * @t: str to con
 * Return: 0 if no num or 0 if con
 */
int _atoi(char *t)
{
	int b, sn = 1, f = 0, opt;
	unsigned int r = 0;
	for (b = 0; t[b] != '\0' && f != 2; b++)
	{
		if (t[b] == '-')
			sn *= -1;

		if (t[b] >= '0' && t[b] <= '9')
		{
			f = 1;
			r *= 10;
			r += (t[b] - '0');
		}
		else if (f == 1)
			f = 2;
	}
	if (sn == -1)
		opt = -r;
	else
		opt = r;
	return (opt);
}
