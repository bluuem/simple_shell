#include "shell.h"

/**
 * **strtow - this func brak a str into words
 * @str: this is the ipt str
 * @d: the delim str
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int t, g, k, m, nwords = 0;
	char **f;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (t = 0; str[t] != '\0'; t++)
		if (!is_delim(str[t], d) && (is_delim(str[t + 1], d) || !str[t + 1]))
			nwords++;

	if (nwords == 0)
		return (NULL);
	f = malloc((1 + nwords) * sizeof(char *));
	if (!f)
		return (NULL);
	for (t = 0, g = 0; g < nwords; g++)
	{
		while (is_delim(str[t], d))
			t++;
		k = 0;
		while (!is_delim(str[t + k], d) && str[t + k])
			k++;
		f[g] = malloc((k + 1) * sizeof(char));
		if (!f[g])
		{
			for (k = 0; k < g; k++)
				free(f[k]);
			free(f);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			f[g][m] = str[t++];
		f[g][m] = 0;
	}
	f[g] = NULL;
	return (f);
}
/**
 * **strtow2 - this func breats str in words
 * @str: this is the ipt str
 * @d: this is the delim
 * Return: it will be a ptr ary str
 */
char **strtow2(char *str, char d)
{
	int t, g, u, m, nwords = 0;
	char **f;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (t = 0; str[t] != '\0'; t++)
		if ((str[t] != d && str[t + 1] == d) ||
				    (str[t] != d && !str[t + 1]) || str[t + 1] == d)
			nwords++;
	if (nwords == 0)
		return (NULL);
	f = malloc((1 + nwords) * sizeof(char *));
	if (!f)
		return (NULL);
	for (t = 0, g = 0; g < nwords; g++)
	{
		while (str[t] == d && str[t] != d)
			t++;
		u = 0;
		while (str[t + u] != d && str[t + u] && str[t + u] != d)
			u++;
		f[g] = malloc((u + 1) * sizeof(char));
		if (!f[g])
		{
			for (u = 0; u < g; u++)
				free(f[u]);
			free(f);
			return (NULL);
		}
		for (m = 0; m < u; m++)
			f[g][m] = str[t++];
		f[g][m] = 0;
	}
	f[g] = NULL;
	return (f);
}
