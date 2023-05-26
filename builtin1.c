#include "shell.h"

/**
 * _myhistory - slows down hist lis one comd
 * @info: Struc has argus
 *  Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets als str
 * @info: pa struct
 * @str: st als
 * Return: 0 s 1e
 */
int unset_alias(info_t *info, char *str)
{
	char *t, h;
	int ret;

	t = _strchr(str, '=');
	if (!t)
		return (1);
	h = *t;
	*t = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*t = h;
	return (ret);
}
/**
 * set_alias - sets alias str
 * @info: pa struct
 * @str: string als
 * Return: 0 s 1 e
 */
int set_alias(info_t *info, char *str)
{
	char *t;

	t = _strchr(str, '=');
	if (!t)
		return (1);
	if (!*++t)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prts alias str
 * @node: alias
 * Return: 0 s 1 f
 */
int print_alias(list_t *node)
{
	char *t = NULL, *b = NULL;

	if (node)
	{
		t = _strchr(node->str, '=');
		for (b = node->str; b <= t; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(t + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias -copis alias builtin
 * @info: Struc has argus
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *t = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		t = _strchr(info->argv[j], '=');
		if (t)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}
	return (0);
}
