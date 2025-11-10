#include "shell.h"

/**
 * shell_loop - runs the shell loop for interactive mode
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status = 1;
	int builtin_status;

	while (status)
	{
		printf("($) ");
		line = read_line();
		args = split_line(line);

		if (args[0] != NULL)
		{
			builtin_status = check_builtin(args);
			if (builtin_status == -1)
				status = 0;
			else if (builtin_status == 0)
				execute(args);
		}

		free(line);
		free_args(args);
	}
}

/**
 * read_line - reads input from stdin
 * Return: pointer to line string
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(0);
		}
		else
		{
			perror("readline");
			exit(1);
		}
	}

	return (line);
}

/**
 * split_line - splits a line into tokens
 * @line: input string
 * Return: array of tokens
 */
char **split_line(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i++] = token;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}
