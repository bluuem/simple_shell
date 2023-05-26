#include "shell.h"

/**
 * _myenv - shows curr envi
 * @info: Struc has argus
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - ve of envi vari
 * @info: Struc hasargus
 * @name: env var name
 * Return: vl
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *t;

	while (node)
	{
		t = starts_with(node->str, name);
		if (t && *t)
			return (t);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - starts new en vari or modis
 * @info: Strue hasargus
 *  Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - takes away en vari
 * @info: Struc has argus
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}
/**
 * populate_env_list - makes en pop
 * @info: Struct has argus
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	info->env = node;
	return (0);
}
