#include "shell.h"

/**
 * is_cmd - this func des if a f is exe com
 * @info: it is the in struc
 * @path: to the f
 * Return: it will be1r /0 o
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dup_chars - this func dups chars
 * @pathstr: it is the pathstr
 * @start: thi going inx
 * @stop: not going inx
 * Return: it will be the poter buf
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char bf[1024];
	int t = 0, j = 0;

	for (j = 0, t = start; t < stop; t++)
		if (pathstr[t] != ':')
			bf[j++] = pathstr[t];
	bf[j] = 0;
	return (bf);
}
/**
 * find_path - this func finds cmd in PATH str
 * @info: it is the in struct
 * @pathstr: it is the PATHstri
 * @cmd: it isthe cmd we need
 * Return: it is the f path of cmdfoun
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int t = 0, cr_pos = 0;
	char *pat;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[t] || pathstr[t] == ':')
		{
			pat = dup_chars(pathstr, cr_pos, t);
			if (!*pat)
				_strcat(pat, cmd);
			else
			{
				_strcat(pat, "/");
				_strcat(pat, cmd);
			}
			if (is_cmd(info, pat))
				return (pat);
			if (!pathstr[t])
				break;
			cr_pos = t;
		}
		t++;
	}
	return (NULL);
}
