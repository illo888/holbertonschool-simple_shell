#include "shell.h"

/**
* execute - executes command
* @args: array of command arguments
* Return: 1 for success
*/
int execute(char **args)
{
pid_t pid;
int status;
char *command_path = find_path(args[0]);

if (command_path == NULL)
{
fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
return (1);
}

pid = fork();
if (pid == 0)
{
if (execve(command_path, args, environ) == -1)
perror("execve");
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("fork");
}
else
{
waitpid(pid, &status, 0);
}

free(command_path);
return (1);
}

