#include "shell.h"

/**
 * is_chain - this ufnc will check ifchar in bgr ischain delim
 * @info: this is the paramr struct
 * @buf: this is the char for the bf
 * @p: this is where the buff is jigim
 * Return: it will be 1 delm
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t g = *p;

	if (buf[g] == '|' && buf[g + 1] == '|')
	{
		buf[g] = 0;
		g++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[g] == '&' && buf[g + 1] == '&')
	{
		buf[g] = 0;
		g++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[g] == ';')
	{
		buf[g] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = g;
	return (1);
}
/**
 * check_chain - this func sees if we must keep chaining
 * @info: it is the pra struct
 * @buf: it is the char for buffer
 * @p: where the bf is now
 * @i: where it starta in the bf
 * @len: it is he len of bf
 * Return: there will be non
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t g = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			g = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			g = len;
		}
	}

	*p = g;
}
/**
 * replace_alias - this func willreplace  aliases in tokenized str
 * @info: it is the parame struc
 * Return: it will be a1 replaced
 */
int replace_alias(info_t *info)
{
	int t;
	list_t *node;
	char *a;

	for (t = 0; t < 10; ++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		a = _strchr(node->str, '=');
		if (!a)
			return (0);
		a = _strdup(a + 1);
		if (!a)
			return (0);
		info->argv[0] = a;
	}
	return (1);
}
/**
 * replace_vars - this func will replace vars intokenized str
 * @info: it is the the param struct
 * Return: it will be 1 replace
 */
int replace_vars(info_t *info)
{
	int t = 0;
	list_t *node;

	for (t = 0; info->argv[t]; t++)
	{
		if (info->argv[t][0] != '$' || !info->argv[t][1])
			continue;

		if (!_strcmp(info->argv[t], "$?"))
		{
			replace_string(&(info->argv[t]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[t], "$$"))
		{
			replace_string(&(info->argv[t]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[t][1], '=');
		if (node)
		{
			replace_string(&(info->argv[t]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[t], _strdup(""));

	}
	return (0);
}
/**
 * replace_string - this func will re st
 * @old: where the old dtr is
 * @new: this is the new str
 * Return: it will be 1 changed
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
