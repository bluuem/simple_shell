#include "shell.h"
/**
 * _myexit - it exc the shell
 * @info: Struc has argus
 * Return: ec with given ec sts
 */
int _myexit(info_t *info)
{
	int ec;

	if (info->argv[1])
	{
		ec = _erratoi(info->argv[1]);
		if (ec == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - it chges cd
 * @info: Strc has args
 * Return: 0
 */
int _mycd(info_t *info)
{
	char *j, *dk, buf[1024];
	int chdir_ret;

	j = getcwd(buf, 1024);
	if (!j)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dk = _getenv(info, "HOME=");
		if (!dk)
			chdir_ret = /* TODO: what should this be? */
				chdir((dk = _getenv(info, "PWD=")) ? dk : "/");
		else
			chdir_ret = chdir(dk);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(j);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dk = _getenv(info, "OLDPWD=")) ? dk : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buf, 1024));
	}
	return (0);
}
/**
 * _myhelp - shanges dir
 * @info: Struc has argus
 * Return: 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;

	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
