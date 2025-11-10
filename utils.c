#include "shell.h"

/**
 * _getenv - gets environment variable value
 * @name: name of the environment variable
 *
 * Return: value of the environment variable or NULL
 */
char *_getenv(char *name)
{
	int i = 0, j;
	char *value;

	if (!name || !environ)
		return (NULL);

	while (environ[i])
	{
		j = 0;
		while (name[j] && environ[i][j] && name[j] == environ[i][j])
			j++;
		if (name[j] == '\0' && environ[i][j] == '=')
		{
			value = &environ[i][j + 1];
			return (value);
		}
		i++;
	}
	return (NULL);
}

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

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = build_full_path(dir, command);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
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
