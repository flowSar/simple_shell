
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

size_t is_absolute(char *str);
char **split_args(char *input_str);
char *allocate_string(char *c);
int execute(char *c, char **envp, pid_t parent_pid);
int is_builtin(char *prog, char **envp, pid_t parent_pid);
char *read_line();
char *read_read_line();

#define UNUSED(x) (void)(x)

#endif
