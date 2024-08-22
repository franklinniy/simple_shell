#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * mysh_cd- Changes directory
 * @args: An array of arguments where args[1] is the direcory
 *
 * Description: Changes directory
 *
 * Return: the result is always 1 to show success
*/

int mysh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "mysh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("mysh");
		}
	}
	return (1);
}

