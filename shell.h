#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/* main_shell.c */
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

/* utils.c */
char *find_path(char *command);
void free_args(char **args);

#endif /* SHELL_H */

