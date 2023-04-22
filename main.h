#ifndef MAIN_H
#define MAIN_H

char *concatenate(char *str, int len);

char **split_string(char *input_str);

char *remove_new_Line(char *str);

int execute(char *command_line, int len, pid_t pid, char **envp);

size_t _getline(char **buffer, size_t buffer_size);

#endif