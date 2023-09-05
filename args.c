#include "main.h"

/**
 * my_exit - function that implemens exit
 * @args: arguments
 *
 * Return : exits shell  or print error number
 */
void my_exit(const char *const args[])
{
	int exit_status = 0;
	const char *err = "Invalid: ";
	const char len = '\n';

	if (args[1] != NULL)
	{
		exit_status = _atoi(args[1]);
	}
	if (exit_status == 0)
	{
		exit(exit_status);
	}
	else
	{
		if (args[1] == NULL)
		{
			exit(0);
		}
		else
		{
			write(2, err, _strlen(err));
			write(2, args[1], _strlen(args[1]));
			write(2, &len, 1);

			exit(2);
		}
	}
}

/**
 * my_env - function that implements environment builtin
 * @name: variables in the environment
 *
 * Return: void
 */
void my_env(char *name[])
{
	int i = 0;
	char **env = environ;
	size_t len = 0;
	(void)name;

	for (i = 0; env[i] != NULL; i++)
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _getenv - function that finds environment
 * @name: variables
 *
 * Return: value of env or NULL if it doesnt exist
 */
char *_getenv(char *name)
{
	char *var = NULL;
	size_t len = strlen(name);
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(name, environ[i], len) == 0)
		{
			var = _strdup(environ[i] + len + 1);
			if (var == NULL)
			{
				perror("Error: ");
			}
			return (var);
		}
	}
	return (NULL);
}

/**
 * handle_my_exit - function that handles exit
 * @status: arguments
 *
 * Return: exit status
 */
void handle_my_exit(char *status)
{
	int exit_status = _atoi(status);
	char exit_g[BUFFER_SIZE];
	int len = _strlen(exit_g), stat_len = 0, t_stat = exit_status;
	int i = 0;
	char temp;
	char st[BUFFER_SIZE];

	do {
		st[stat_len++]  = t_stat % 10 + '0';
		t_stat /= 10;
	}

	while (t_stat > 0);

	for (i = 0; i < stat_len / 2; i++)
	{
		temp = st[i];
		st[i] = st[stat_len - i - 1];
		st[stat_len - i - 1] = temp;
	}
	for (i = 0; i < stat_len; i++)
	{
		exit_g[len + i] = st[i];
	}
	exit_g[len + stat_len] = '\0';

	write(STDOUT_FILENO, exit_g, len + stat_len);
	write(STDOUT_FILENO, "\n", 1);

	exit(exit_status);
}

/**
 * exec_build_cmd - function that executes builtin
 * @args: arguments
 *
 * Return: void
 */
void exec_build_cmd(char **args)
{
	if (args[0] == NULL)
	{
		return;
	}
	if (_strcmp(args[0], "cd") == 0)
	{
		my_cd(*args);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		_setenv(args[0], *args);
		return;
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		_unsetenv(*args);
		return;
	}
	else
	{
		execve_func(args, args);
	}
}
