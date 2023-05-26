#include "shell.h"

/**
 * input_buf - this func buffs ch comnds
 * @info: it is a para strct
 * @buf: where the buff will be found
 * @len: where the len var will be found
 * Return: it will be the prt byts
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t y = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		y = getline(buf, &len_p, stdin);
#else
		y = _getline(info, buf, &len_p);
#endif
		if (y > 0)
		{
			if ((*buf)[y - 1] == '\n')
			{
				(*buf)[y - 1] = '\0';
				y--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = y;
				info->cmd_buf = buf;
			}
		}
	}
	return (y);
}
/**
 * get_input - this funcgets a line and takes away nl
 * @info: it is the parastruct
 * Return: the orinted byts
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t o, k, lh;
	ssize_t y = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	y = input_buf(info, &buf, &lh);
	if (y == -1)
		return (-1);
	if (lh)
	{
		k = o;
		p = buf + o;

		check_chain(info, buf, &k, o, lh);
		while (k < lh)
		{
			if (is_chain(info, buf, &k))
				break;
			k++;
		}

		o = k + 1;
		if (o >= lh)
		{
			o = lh = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (y);
}
/**
 * read_buf - this func rs a buf
 * @info: the para struc
 * @buf: bit a buf
 * @i: it is the sz
 * Return: it will be y
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t y = 0;

	if (*i)
		return (0);
	y = read(info->readfd, buf, READ_BUF_SIZE);
	if (y >= 0)
		*i = y;
	return (y);
}
/**
 * _getline - it will getnx line of ipt
 * @info: the param struct
 * @ptr: where the ptr will be found
 * @length: len of pa ptr buf
 * Return: it will be d
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t j, lh;
	size_t t;
	ssize_t y = 0, d = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		d = *length;
	if (j == lh)
		j = lh = 0;

	y = read_buf(info, buf, &lh);
	if (y == -1 || (y == 0 && lh == 0))
		return (-1);

	c = _strchr(buf + j, '\n');
	t = c ? 1 + (unsigned int)(c - buf) : lh;
	new_p = _realloc(p, d, d ? d + t : t + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (d)
		_strncat(new_p, buf + j, t - j);
	else
		_strncpy(new_p, buf + j, t - j + 1);

	d += t - j;
	j = t;
	p = new_p;

	if (length)
		*length = d;
	*ptr = p;
	return (d);
}
/**
 * sigintHandler - stops ctrl
 * @sig_num: it he sn numb
 * Return: wont work
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
