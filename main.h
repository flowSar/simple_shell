#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *strcat_all(char *name, char *sep, char *value);

char **splits_string(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_path - list of paths dirs
 * @dir: dir of path
 * @p: ptr to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *_getenv(const char *name);
list_path *append_node(list_path **head, char *str);
list_path *path_list(char *path);
char *find_pathname(char *filename, list_path *head);

/**
 * struct builtins - pointer to function with the corresponding builtin command
 * @name: builtin command
 * @func: func of the buildin command
 */
typedef struct builtins
{
	char *name;
	void (*func)(char **);
} builtins;

void(*is_builtin(char **arv))(char **arv);
int _atoi(char *s);
void exit_handler(char **arv);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);

void free_argv(char **arv);
void free_list(list_path *head);

char *concat(char *str, int len);

char **split_string(char *input_str);


#endif
