#ifndef MAIN_H
#define MAIN_H
#include <stddef.h> 
char *concatenate(char *str);

char **split_string(char *input_str);

char *remove_new_Line(char *str);

char **execu_prepare(char **envp);

int isbuildin(char *command, char **args, char **envp);

size_t _getline(char **buffer, size_t buffer_size);

void write_pipe_msg(char **msg);

int _isEqual(char *str1, char *str2);

void free_memory(char **list);

int _strlen(char *str);

char *_strcpy(char *str1, char *str2);

void *_realloc(void *str, int new_size);

#endif