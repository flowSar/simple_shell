#ifndef MAIN_H
#define MAIN_H
typedef struct lis
{
	char **args;
	char *command;
} LIST;


char *concatenate(char *str);

char **split_By(char *str, char flag);

char *clean_command(char *str);

LIST *execu_prepare(char **envp);

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

#endif
