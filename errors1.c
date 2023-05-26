#include "shell.h"

/**
 * _erratoi - changes str to int
 * @s: str to change
 * Return: 0 if there is no numbs
 */
int _erratoi(char *s)
{
	int j = 0;
	unsigned long int rst = 0;

	if (*s == '+')
		s++;
	for (j = 0;  s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			rst *= 10;
			rst += (s[j] - '0');
			if (rst > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rst);
}
/**
 * print_error - it will write out and e mes
 * @info: it is the para and r in st
 * @estr: it has error str
 * Return: 0 if no nums/ con num -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - fun shows dec number (base 10)
 * @input: its the input
 * @fd: isfiledescriptor
 * Return: numb char shown
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, cou = 0;
	unsigned int _abs_, crt;

	if (fd == STDERR_FILENO)
		__putchar = _putchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		cou++;
	}
	else
		_abs_ = input;
	crt = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + crt / j);
			cou++;
		}
		crt %= j;
	}
	__putchar('0' + crt);
	cou++;

	return (cou);
}
/**
 * convert_number - conver func
 * @num: its anumb
 * @base: its abase
 * @flags: its aargu
 * Return: str
 */
char *convert_number(long int num, int base, int flags)
{
	static char *ary;
	static char buf[50];
	char sn = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sn = '-';

	}
	ary = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do	{
		*--ptr = ary[n % base];
		n /= base;
	} while (n != 0);

	if (sn)
		*--ptr = sn;
	return (ptr);
}
/**
 * remove_comments - func changes com
 * @buf: address of str needs change
 * Return: 0
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
