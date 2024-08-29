#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
 * find_command_in_path - Finds a command in the PATH.
 * @command: The name of the command to search for.
 *
 * Return: The full path or NULL if not found.
 */

char *find_command_in_path(char *command)

{
	char *path;
	char *path_dup;
	char *dir;
	char *result;
	char full_path[1024];

	path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		return (NULL);
	}

	path_dup = strdup(path);

	if (path_dup == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	dir = strtok(path_dup, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
			if (access(full_path, X_OK) == 0)
			{
				result = strdup(full_path);
				free(path_dup);
				return (result);
			}
			dir = strtok(NULL, ":");
	}
	free(path_dup);
	return (NULL);
}

