#include "shell.h"

/**
 * bfree - this func frees ptr
 * @ptr: it is where the ptr of bfree iss
 * Return: it will eb 1 fre/ 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
