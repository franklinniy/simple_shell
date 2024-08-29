#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * change_directory - Changes the current working directory.
 * @path: The new path to change to.
 *
 * Return: 0 on success, -1 on failure.
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
