#include "shell.h"

/**
 * find_path - finds full path of a command
 * @command: the command to find
 *
 * Return: full path string or NULL if not found
 */
char *find_path(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (command == NULL)
		return (NULL);

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * free_args - frees the array of arguments
 * @args: array of strings to free
 *
 * Note: Does not free individual strings as they point
 * to memory managed by the line buffer
 */
void free_args(char **args)
{
	if (args)
		free(args);
}
