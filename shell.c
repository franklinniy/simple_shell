#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * @brief Changes the current working directory.
 *
 * This function changes the current working directory to the path provided.
 * If no path is provided, it changes to the user's home directory.
 *
 * @param path The directory to change to. If NULL, changes to the home
 */

void change_directory(char *path)
{
	if (path == NULL)
	{
		path = getenv("HOME");
	}
	if (chdir(path) != 0)
	{
		perror("cd");
	}
}
void print_working_directory(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("pwd");
	}
}
int handle_builtin_commands(char *args[])
{
	if (strcmp(args[0], "cd") == 0)
	{
		change_directory(args[1]);
		return (1);
	}
	else if (strcmp(args[0], "pwd") == 0)
	{
		print_working_directory();
		return (1);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	return (0);
}


int main(void)
{
	char command[1024];
	char *args[10];
	char *token;
	int i;

	while (1)
	{
		printf("mysh> ");
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = 0;
		token  = strtok(command, " ");

		i = 0;

		while (token != NULL && i < 9)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
		if (args[0] == NULL)
		{
			continue;
		}
		if (handle_builtin_commands(args) == 0)
		{
			printf("Command not found: %s\n", args[0]);
		}
	}
	return (0);
}
