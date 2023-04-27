#include "main.h"

size_t is_absolute(char *str)
{
	size_t i = 0;     
	
	while (str[i] != '\0' && str[i] != '/')
	{
		i++;
	}
	
	return (i != strlen(str) || str[i] == '/');
}

/**
  * execute - passes a string to execve sys call
  * @c: pointer to string to be executed
  * @envp: envp vars passed by main prog
  * @parent_pid: main process pid
  * Return: whatever execve returned
  */
int execute(char *c, char **envp, pid_t parent_pid)
{

	int exec_value;
	char **args_list = split_args(c);
	char command[1024] = "";
	char *new_command;

	char *path = "/usr/bin/";

	/*check for built-ins*/
	if (is_builtin(args_list[0], envp, parent_pid) == 1)
	{
		;
	}

	else
	{
	
		/**
		 * printf("About to execute : \'%s\'\n", args_list[0]);
		 * printf("is absolute : %d\n", is_absolute(args_list[0]));
		 * printf("args[0] : %s\n", args_list[0]);
		*/

		if (is_absolute(args_list[0]) == 0)
		{
			/*printf("adding path\n");*/
			strcat(command, path);
			strcat(command, args_list[0]);
			strcat(command, "\n");
			new_command = allocate_string(command);
			/*printf("%s\n", new_command);*/
			exec_value = execve(new_command, args_list, envp);
			/*printf("exec = %d\n", exec_value);*/
		}
		else
		{
			exec_value = execve(args_list[0], args_list, envp);
		}
			if (exec_value == -1)
				printf("ERROR : File exists but execuve(-1)\n");

	}

	exit(-1);

	return (exec_value); /*just in case the kernel cought in fire*/
}
