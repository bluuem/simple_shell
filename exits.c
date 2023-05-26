#include "shell.h"

/**
 **_strncpy - it will replicate a str
 *@dest: wher te str will be replicated
 *@src: the one og
 *@n: the numb of char to be replicated
 *Return: con str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j, t;
	char *s = dest;

	j = 0;
	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
	{
		t = j;
		while (t < n)
		{
			dest[t] = '\0';
			t++;
		}
	}
	return (s);
}
/**
 **_strncat - it cons 2 strs
 *@dest: 1 str
 *@src: 2str
 *@n: most amou byt to av
 *Return: it will be the con str
 */
char *_strncat(char *dest, char *src, int n)
{
	int j, t;
	char *s = dest;

	j = 0;
	t = 0;
	while (dest[j] != '\0')
		j++;
	while (src[t] != '\0' && t < n)
	{
		dest[j] = src[t];
		j++;
		t++;
	}
	if (t < n)
		dest[j] = '\0';
	return (s);
}
/**
 **_strchr - it finds a char in str
 *@s: the str to show
 *@c: chartofind
 *Return: a ptr mem area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
