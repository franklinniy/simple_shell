#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

