#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * find_command_in_path - Finds the full path of an executable command.
 *
 * @command: The command to search for.
 *
 * Searches for the command in the system's PATH
 *
 * Return: Full path of the command or NULL if not found.
 */
char *find_command_in_path(const char *command)
{
	char *path_env, *path, full_path[1024], *token;

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}
	path_env = getenv("PATH");

	if (path_env)
	{
		path = strdup(path_env);
		token = strtok(path, ":");
		while (token != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
			if (access(full_path, X_OK) == 0)
			{
				free(path);
				return (strdup(full_path));
			}
			token = strtok(NULL, ":");
		}
		free(path);
	}
	return (NULL);
}

