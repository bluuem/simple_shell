#include "shell.h"

/**
 * get_environ - this func prints the str ary copy of en
 * @info: it is Stru that has argus
 * Return: 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
/**
 * _unsetenv -this func takes away env var
 * @info: it is a  stru argus
 *  Return: 1 when removes or 0
 * @var: it is the str env var pro
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t o = 0;
	char *a;

	if (!node || !var)
		return (0);

	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), o);
			o = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		o++;
	}
	return (info->env_changed);
}
/**
 * _setenv - make snew env var or changes another
 * @info: it is the structhat has argu
 * @var: it is the str env var prop
 * @value: it is the val of srt env var
 *  Return: 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *bf = NULL;
	list_t *node;
	char *a;

	if (!var || !value)
		return (0);

	bf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!bf)
		return (1);
	_strcpy(bf, var);
	_strcat(bf, "=");
	_strcat(bf, value);
	node = info->env;
	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			free(node->str);
			node->str = bf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), bf, 0);
	free(bf);
	info->env_changed = 1;
	return (0);
}
