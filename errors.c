#include "shell.h"

/**
 * _eputs - reads ipt str
 * @str: to be shown
 * Return: None
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}
/**
 * _eputchar - wri c to stder
 * @c: to be shown
 * Return: S 1 E -1 and set properly
 */
int _eputchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}
/**
 * _putfd - writes c tofd
 * @c: to be shown
 * @fd: isfiledescriptor
 * Return: S 1 E -1 then set properly
 */
int _putfd(char c, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}
/**
 * _putsfd - prts ipt stri
 * @str: to be shown printed
 * @fd: isfiledescriptor wr
 * Return: it wil return numb chars
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
