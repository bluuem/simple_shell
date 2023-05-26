#include "shell.h"

/**
 * list_len - this func chooses len of linked list
 * @h: it is the ptr ofnode1
 * Return: it will be the sz of list
 */
size_t list_len(const list_t *h)
{
	size_t t = 0;

	while (h)
	{
		h = h->next;
		t++;
	}
	return (t);
}
/**
 * list_to_strings - this func willreturnary of str
 * @head: it is the ptr node1
 * Return: it will be an ary of strs
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t t = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !t)
		return (NULL);
	strs = malloc(sizeof(char *) * (t + 1));
	if (!strs)
		return (NULL);
	for (t = 0; node; node = node->next, t++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < t; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[t] = str;
	}
	strs[t] = NULL;
	return (strs);
}
/**
 * print_list - this funcprts eles of list_t l l
 * @h: it is the  ptr to 1 nd
 * Return: it will return the size of list
 */
size_t print_list(const list_t *h)
{
	size_t t = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		t++;
	}
	return (t);
}
/**
 * node_starts_with - this func brings back nde str start prefix
 * @node: it is the ptr to lhead
 * @prefix: it is str to match
 * @c: it is the the nxt charto match
 * Return: it will match n or non
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *a = NULL;

	while (node)
	{
		a = starts_with(node->str, prefix);
		if (a && ((c == -1) || (*a == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index - this funcgets the inx node
 * @head: it is the ptr to lt h
 * @node: it is the ptr to the n
 * Return: it will be theinx of n or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t t = 0;

	while (head)
	{
		if (head == node)
			return (t);
		head = head->next;
		t++;
	}
	return (-1);
}
