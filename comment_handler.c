#include "shell.h"

/**
 * remove_comment - removes comments from a line
 * @line: the line to process
 *
 * Return: void
 */
void remove_comment(char *line)
{
	int i = 0;

	if (line == NULL)
		return;

	while (line[i])
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
}
