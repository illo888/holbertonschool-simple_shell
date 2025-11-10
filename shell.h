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

/* shell.c */
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);

/* execute.c */
int execute(char **args);

/* utils.c */
char *_getenv(char *name);
char *find_path(char *command);
void free_args(char **args);

/* builtins.c */
int builtin_env(void);
int builtin_exit(char **args);
int check_builtin(char **args);

/* error_handler.c */
void print_error(char *program_name, char *cmd, char *msg);
int get_exit_status(int status);

#endif /* SHELL_H */
