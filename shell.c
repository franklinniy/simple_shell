#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - shell loop
 *
 * Description: reads input from the uset
 *
 * Return: the result is always 0 to show success
*/

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_TOKENS];
	char *token;
	int status;
	int i;
	pid_t pid;

	while (1)

	{
		printf("mysh>");
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		printf("You entered: %s\n", input);
	}
	i = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("mysh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("mysh");
	} else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
