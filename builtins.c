#include "shell.h"

/**
 * builtin_env - prints the current environment
 *
 * Return: 0 on success
 */
int builtin_env(void)
{
	int i = 0;

	if (environ == NULL)
		return (1);

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}

/**
 * builtin_exit - exits the shell
 * @args: array of arguments (unused for basic exit)
 *
 * Return: 0 to exit
 */
int builtin_exit(char **args)
{
	(void)args;
	return (0);
}

/**
 * check_builtin - checks if command is a builtin and executes it
 * @args: array of command arguments
 *
 * Return: 1 if builtin was executed, 0 if not a builtin
 */
int check_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "env") == 0)
	{
		builtin_env();
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		return (-1);
	}

	return (0);
}
