#include "shell.h"

/**
 * _strcpy - this funccops a stri
 * @dest: it is the des
 * @src: the source the og
 * Return: it will beptr  des
 */
char *_strcpy(char *dest, char *src)
{
	int t = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[t])
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = 0;
	return (dest);
}
/**
 * _strdup - this funcdupes a str
 * @str: the str to dup
 * Return: it will beptrdup stri
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *rt;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	rt = malloc(sizeof(char) * (len + 1));
	if (!rt)
		return (NULL);
	for (len++; len--;)
		rt[len] = *--str;
	return (rt);
}
/**
 * _puts - this funcprts an inpt str
 * @str: thi is the strin prted
 * Return: non
 */
void _puts(char *str)
{
	int t = 0;

	if (!str)
		return;
	while (str[t] != '\0')
	{
		_putchar(str[t]);
		t++;
	}
}
/**
 * _putchar - this func wrs the char c to sdop
 * @c: this is the char to prt
 * Return: On success 1
 */
int _putchar(char c)
{
	static int t;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(1, buf, t);
		t = 0;
	}
	if (c != BUF_FLUSH)
		buf[t++] = c;
	return (1);
}
