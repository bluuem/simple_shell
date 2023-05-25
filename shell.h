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

#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1

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
 * struct liststr - sldlst
 * @num: the num of the field
 * @str: just a string
 * @next: this will point to n n
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;
/* this is for  toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bfree(void **);

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

int _myhistory(info_t *);
int _myalias(info_t *);

/**
 * struct builtin - cons builtin stri and func
 * @type: this is the builtin comnd fla
 * @func: this is the func of the code
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/**
 * struct passinfo - this cons pseudo-arguements to give to the func
 * @arg: this string gener from gl that has the argu
 * @argv: this is aray strings gener from the arg
 * @path: str path fr thecommand
 * @argc: arg count
 * @line_count:  error of the count
 * @err_num: error code exit()s
 * @linecount_flag: this count of the line of input
 * @fname: the file name of the prog
 * @env: cp of the link lis of the env
 * @environ: modified copy of the environ
 * @history: this is the history code
 * @alias: the allisa of the node
 * @env_changed: on when the env will be ch
 * @status: the print sts of the fine comd
 * @cmd_buf: where the poinn of the cmdbuf will be found
 * @cmd_buf_type: CMD_type
 * @readfd: the fd from which to read line input
 * @histcount: the count of the hist
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
#endif
