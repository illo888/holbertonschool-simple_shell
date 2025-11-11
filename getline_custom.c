#include "shell.h"

/**
 * _getline - custom implementation of getline
 * @lineptr: pointer to store the input line
 * @n: size of the buffer (updated if needed)
 * @stream: input stream (usually stdin)
 *
 * Return: number of characters read, or -1 on failure or EOF
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[1024];
	static size_t buf_pos, buf_size;
	size_t line_len = 0;
	char *new_line = NULL;
	char c;

	if (!lineptr || !n || !stream)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}

	while (1)
	{
		if (buf_pos >= buf_size)
		{
			buf_size = read(fileno(stream), buffer, sizeof(buffer));
			if (buf_size == 0)
				return (line_len ? (ssize_t)line_len : -1);
			if (buf_size < 0)
				return (-1);
			buf_pos = 0;
		}

		c = buffer[buf_pos++];

		if (line_len + 1 >= *n)
		{
			*n *= 2;
			new_line = realloc(*lineptr, *n);
			if (!new_line)
				return (-1);
			*lineptr = new_line;
		}

		(*lineptr)[line_len++] = c;

		if (c == '\n')
			break;
	}

	(*lineptr)[line_len] = '\0';
	return (line_len);
}

