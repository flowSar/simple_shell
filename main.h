#ifndef MAIN_H
#define MAIN_H

char *concatenate(char *str, int len);

char **split_string(char *input_str);

char *remove_new_Line(char *str);

void execute(char *command ,int len, pid_t pid);

#endif