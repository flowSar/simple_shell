#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _getline- this functio read from standard input to the buffer.
 * @buffer: aloccated memory to where will store readed data.
 * @buffer_size: size of buffer.
 * Return: size of data readed from stdin .
 */

size_t _getline(char **buffer, size_t buffer_size)
{
	size_t bytes_red;
	*buffer = malloc(buffer_size * sizeof(char));

	bytes_red = read(0, *buffer, buffer_size);

	return (bytes_red);
}
