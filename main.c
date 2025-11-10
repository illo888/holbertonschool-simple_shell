#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	int builtin_status;

	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
	{
		shell_loop();
	}
	else
	{
		while (getline(&line, &len, stdin) != -1)
		{
			args = split_line(line);
			if (args[0] != NULL)
			{
				builtin_status = check_builtin(args);
				if (builtin_status == -1)
				{
					free_args(args);
					free(line);
					break;
				}
				else if (builtin_status == 0)
				{
					execute(args);
				}
			}
			free_args(args);
		}
		free(line);
	}

	return (0);
}
