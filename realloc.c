#include "shell.h"

/**
 * _memset - this func fills mem with a const bite
 * @s: this is the ptr to mem
 * @b: this is tthe bite to put by s
 * @n: this is the num of bytes to put
 * Return: it will be a ptr to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int m;

	for (m = 0; m < n; m++)
		s[m] = b;
	return (s);
}
/**
 * ffree - this func frees a str of strs
 * @pp: it is the str of strs
 */
void ffree(char **pp)
{
	char **h = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(h);
}
/**
 * _realloc - this func finds a b of mem
 * @ptr: it is the ptr to old malloc'ated b
 * @old_size: it is the byte sz of old b
 * @new_size: it is the byte sz of new b
 * Return: it will be the ptr of old b
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	a = malloc(new_size);
	if (!a)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		a[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (a);
}
