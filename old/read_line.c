#include "main.h"

char *read_line()
{
	char *buffer = malloc(sizeof(char *));
	size_t bufsize = 1024;
	char *new_buffer = malloc(sizeof(char *));

	if (buffer == NULL || new_buffer == NULL)
	{
		perror("malloc() failed : Unable to allocate buffer\n");
		free(buffer);
		free(new_buffer);
		exit(-1);
	}

	printf("$ ");
	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		/*end of file encountred*/
		free(buffer);
		free(new_buffer);
		exit(0);
	}

	new_buffer = allocate_string(buffer);

	return (new_buffer);
}
