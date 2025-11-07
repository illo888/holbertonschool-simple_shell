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
    (void)argc;
    (void)argv;

    if (isatty(STDIN_FILENO))
        shell_loop();
    else
    {
        char *line = NULL;
        size_t len = 0;

        while (getline(&line, &len, stdin) != -1)
        {
            char **args = split_line(line);
            if (args[0] != NULL)
                execute(args);
            free_args(args);
        }
        free(line);
    }

    return (0);
}
