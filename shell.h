#ifndef SHELL_H
#define SHELL_H

int mysh_cd(char **args);
int handle_builtin_commands(char *args[]);
char *find_command_in_path(char *command);

#endif

