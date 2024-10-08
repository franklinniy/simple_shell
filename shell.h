#ifndef SHELL_H
#define SHELL_H

extern char **environ;
int mysh_cd(char **args);
int handle_builtin_commands(char *args[]);
char *find_command_in_path(char *command);
void print_environment(void);
void execute_ls(char *args[]);
void print_working_directory(void);
void change_directory(char *path);

#endif

