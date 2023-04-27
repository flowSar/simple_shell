#ifndef MAIN_H
#define MAIN_H

char *concatenate(char *str, int len);

char **split_string(char *input_str);

char *remove_new_Line(char *str);

int execute(char *command_line, int len, pid_t pid, char **envp, char *pname);

size_t _getline(char **buffer, size_t buffer_size);

void write_pipe_msg(char **msg);

int _isEqual(char *str1, char *str2);

void free_memory(char **list);

int _strlen(char *str);

char *_strcpy(char *str1, char *str2);

void *_realloc(void *str, int new_size);

#endif
