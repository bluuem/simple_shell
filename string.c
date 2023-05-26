#include "shell.h"

/**
 * _strlen - this func res the l of str
 * @s: the str len to look at
 * Return: it will be in le of str
 */
int _strlen(char *s)
{
	int t = 0;

	if (!s)
		return (0);

	while (*s++)
		t++;
	return (t);
}
/**
 * _strcmp - this func does lexicogarphic comp
 * @s1: the star 1
 * @s2: the star 2
 * Return: it will be - s1 < s2 + s1 > s2 0  s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - this func looks if needle has hayst
 * @haystack: this is a str to look
 * @needle: it is the one to be found
 * Return: it will be wher nxt char of haystack or non
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - this func cons t2 strs
 * @dest: this is the dest buff
 * @src: this is the og buff
 * Return: it will be the ptr des to buff
 */
char *_strcat(char *dest, char *src)
{
	char *rt = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rt);
}
