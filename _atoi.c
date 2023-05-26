#include "shell.h"

/**
 * interactive - cbs tr is shell works
 * @info: address of struc
 * Return: 1\0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - see if char is delim
 * @c: the char
 * @delim: the str
 * Return: 1\0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - will see if alpha
 * @c: the inpu
 * Return: it will be  1 if c is alpha
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - it cons a str to int
 * @s: what needs to be con
 * Return: it will be 0 if no numbs in str con numb
 */

int _atoi(char *s)
{
	int i, sn = 1, fg = 0, opt;
	unsigned int r = 0;

	for (i = 0; s[i] != '\0' && fg != 2; i++)
	{
		if (s[i] == '-')
			sn *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			fg = 1;
			r *= 10;
			r += (s[i] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}

	if (sn == -1)
		opt = -r;
	else
		opt = r;
	return (opt);
}
