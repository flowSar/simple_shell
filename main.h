#ifndef MAIN_H
#define MAIN_H
typedef struct lis
{
	char **args;
	char *command;
	int status;
} cmd_args;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

char *concatenate(char *str);

char **split_By(char *str, char flag);

char *clean_command(char *str);

char **execu_prepare(char **envp);

void execute(char **cmd, char **envp);

int isbuildin(char *command, char **args, char **envp);

size_t _getline(char **buffer, size_t buffer_size);

void write_pipe_msg(char **msg);

int _isEqual(char *str1, char *str2);

int _putchar(char c);


void free_memory(char **list);

void *_realloc(void *str, int new_size);

int _strlen(char *str);

int _printf(char *str);

char *_strcpy(char *str1, char *str2);

int get_chuck_number(char *str);

char *get_chunck(char *str, int start, int end);

void sigint_handler(__attribute__((unused))int sig);

#endif
