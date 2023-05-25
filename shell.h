#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* this is for r/w bufs */
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1

/* this is for comnd chai */
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CMD_NORM	0

/* this is for conve_num() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* this will re 1 if using stem gtl() */
#define USE_STRTOK 0
#define USE_GETLINE 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
extern char **environ;

/**
 * struc listr - sldlst
 * @num: the num of the field
 * @str: just a string
 * @next: this will point to n n
 */

