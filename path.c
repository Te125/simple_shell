#include "main.h"

/**
 * get_path - function to get path
 * @command: commands to execute
 *
 * Return: fullp or NULL if not available
 */
char *get_path(const char *command)
{
	struct stat st;
	char *path = _getenv("PATH");
	char *fullp = NULL;
	size_t fullp_len = _strlen(command) + 1;
	char *token = NULL;

	if (!path || !command)
	{
		free(path);
		return (NULL);
	}

	token = strtok(path, ":");
	while (token)
	{
		fullp = (char *)malloc(fullp_len);
		if (!fullp)
		{
			perror("Memory error");
			free(path);
			free(fullp);
			return (NULL);
		}
		_strcpy(fullp, token);
		_strcat(fullp, "/");
		_strcat(fullp, command);
		_strcat(fullp, "\0");
		if (stat(fullp, &st) == 0)
		{
			/*free(path);*/
			return (fullp);
		}
		free(fullp);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
