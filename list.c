#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * execute_ls - Executes the `ls` command.
 *
 * @args: Arguments for the `ls` command.
 *
 * Forks a process to execute `/bin/ls` with the given arguments
 */
void execute_ls(char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execv("/bin/ls", args);
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
}

