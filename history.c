#include "shell.h"

/**
 * get_history_file - this func ge hisfile
 * @info: it is the param struct
 * Return: it will return allo str that has the hf
 */

char *get_history_file(info_t *info)
{
	char *bf, *r;

	r = _getenv(info, "HOME=");
	if (!r)
		return (NULL);
	bf = malloc(sizeof(char) * (_strlen(r) + _strlen(HIST_FILE) + 2));
	if (!bf)
		return (NULL);
	bf[0] = 0;
	_strcpy(bf, r);
	_strcat(bf, "/");
	_strcat(bf, HIST_FILE);
	return (bf);
}
/**
 * write_history - this func will make a f or atatches
 * @info: it is the param struct
 * Return: 1 on suc o -1 f
 */
int write_history(info_t *info)
{
	ssize_t f;
	char *fname = get_history_file(info);
	list_t *node = NULL;

	if (!fname)
		return (-1);

	f = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (f == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, f);
		_putfd('\n', f);
	}
	_putfd(BUF_FLUSH, f);
	close(f);
	return (1);
}
/**
 * read_history - this func will r hist
 * @info: this is the para struct
 * Return: it will return thehct issuc
 */
int read_history(info_t *info)
{
	int o, lt = 0, lct = 0;
	ssize_t f, rdlen, fsz = 0;
	struct stat st;
	char *bf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	f = open(filename, O_RDONLY);
	free(filename);
	if (f == -1)
		return (0);
	if (!fstat(f, &st))
		fsz = st.st_size;
	if (fsz < 2)
		return (0);
	bf = malloc(sizeof(char) * (fsz + 1));
	if (!bf)
		return (0);
	rdlen = read(f, bf, fsz);
	bf[fsz] = 0;
	if (rdlen <= 0)
		return (free(bf), 0);
	close(f);
	for (o = 0; o < fsz; o++)
		if (bf[o] == '\n')
		{
			bf[o] = 0;
			build_history_list(info, bf + lt, lct++);
			lt = o + 1;
		}
	if (lt != o)
		build_history_list(info, bf + lt, lct++);
	free(bf);
	info->histcount = lct;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list - this func adds entra to hist ll
 * @info: it sis struc that hasargus
 * @buf: it is the buf
 * @linecount: it is the his lct
 * Return: 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}
/**
 * renumber_history - this func will renumb hist llist
 * @info: it isstruc that hasargus
 * Return: it will return the n htct
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int o = 0;

	while (node)
	{
		node->num = o++;
		node = node->next;
	}
	return (info->histcount = o);
}
