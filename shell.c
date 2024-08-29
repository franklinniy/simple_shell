#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * print_environment - Prints all the environment variables.
 *
 * Return: Nothing.
 */

void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * handle_builtin_commands - Executes built-in shell commands.
 * @args: The arguments passed to the command.
 *
 * Return: 0 if a built-in command was executed, 1 otherwise.
 */
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
	else if (strcmp(args[0], "env") == 0)
	{
		print_environment();
		return (0);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	return (0);
}
/**
 * execute_command - Executes a command using execv.
 *
 * @args: An array of arguments to pass to execv.
 *
 * Forks a new process to execute the command and waits
 */

void execute_command(char *args[])
{
	char *cmd_path = find_command_in_path(args[0]);
	pid_t pid;

	if (cmd_path)
	{
		printf("Executing command: %s\n", cmd_path);
		pid = fork();

		if (pid == 0)
		{
			execv(cmd_path, args);
			perror("execv");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
		}
		free(cmd_path);
	}
	else
	{
		printf("Command not found: %s\n", args[0]);
	}
}
/**
 * handle_input - Reads and processes user input.
 *
 * This function displays the shell prompt, reads user input
 *
 * Return- returns 0
 */
void handle_input(void)
{
	char command[1024], *args[10], *token;
	int i;

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			perror("fgets");
			continue;
		}
		command[strcspn(command, "\n")] = 0;
		token = strtok(command, " ");
		for (i = 0; token != NULL && i < 9; i++)
		{
			args[i] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (args[0] == NULL || handle_builtin_commands(args) != 0)
			continue;
		execute_command(args);
	}
}

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	handle_input();
	return (0);
}
