#include "shell.h"

/**
 * hsh - this func is themain shell loop
 * @info: this is the para struct in re
 * @av: it  is the argu vec
 * Return: it will be0 suc 1 er er code
 */
int hsh(info_t *info, char **av)
{
	ssize_t b = 0;
	int builtin_rt = 0;

	while (b != -1 && builtin_rt != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		b = get_input(info);
		if (b != -1)
		{
			set_info(info, av);
			builtin_rt = find_builtin(info);
			if (builtin_rt == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_rt == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_rt);
}
/**
 * find_builtin - this func will finds a builtin com
 * @info: this is the para and struct in re
 * Return: -1 nfound 0 esuc 1 fnsuc 2 snexit
 */
int find_builtin(info_t *info)
{
	int t, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (t = 0; builtintbl[t].type; t++)
		if (_strcmp(info->argv[0], builtintbl[t].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[t].func(info);
			break;
		}
	return (built_in_ret);
}
/**
 * find_cmd - this func finds a com
 * @info: it is the para and struct re
 * Return: it wont be shown
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int t, j;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (t = 0, j = 0; info->arg[t]; t++)
		if (!is_delim(info->arg[t], " \t\n"))
			j++;
	if (!j)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
/**
 * fork_cmd - this func forks a exec thre for cmd
 * @info: it is the para and info struct re
 * Return: it wont be shown
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
