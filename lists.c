#include "shell.h"

/**
 * add_node - this fun adds a node to the beg
 * @head: where youll find head ptr
 * @str: it is the str fd of node
 * @num: it is used bu hidt
 * Return: it wirll besize
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *n_head;

	if (!head)
		return (NULL);
	n_head = malloc(sizeof(list_t));
	if (!n_head)
		return (NULL);
	_memset((void *)n_head, 0, sizeof(list_t));
	n_head->num = num;
	if (str)
	{
		n_head->str = _strdup(str);
		if (!n_head->str)
		{
			free(n_head);
			return (NULL);
		}
	}
	n_head->next = *head;
	*head = n_head;
	return (n_head);
}
/**
 * add_node_end - this funcadds a node to the end of the list
 * @head: whrer the og node will be found
 * @str: it is the field
 * @num: it is used by hist
 * Return: it will be the size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
/**
 * print_list_str - this funct only ptrs the node lst
 * @h: it is the ptr of node1
 * Return: it will show how th lis is
 */
size_t print_list_str(const list_t *h)
{
	size_t t = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		t++;
	}
	return (t);
}
/**
 * delete_node_at_index - this func dels node
 * @head: it is whre youll find the ptr of 1 node
 * @index: the node to be rremoved
 * Return: 1s 0 f
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int t = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (t == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		t++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
/**
 * free_list - this func will free a ll lis
 * @head_ptr: it is where youll find head ptr
 * Return: it will not show
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
