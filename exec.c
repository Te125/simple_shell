#include "main.h"

/**
 * execve_func - function that executes
 * @args: arguments
 * @env: environment array
 *
 * Return: nothing
 */
void execve_func(char **args, char *const env[])
{
	int i = 0;
	pid_t pid;
	char *cmd = args[0];
	char *x = "\n";
	char *path_cmd = NULL;

	if (cmd[0] != '/' && cmd[0] != ':')
	{
		path_cmd = get_path(cmd);
		if (!path_cmd)
		{
			write(STDERR_FILENO, cmd, _strlen(cmd));
			write(STDERR_FILENO, x, _strlen(x));
			return;
		}
		args[0] = path_cmd;
	}
	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, "Fork failed\n", 12);
		free(path_cmd);
		return;
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(args[0], args, env) == -1)
		{
			write(STDERR_FILENO, "Error\n", 7);
			free(path_cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(path_cmd);
		waitpid(pid, &i, WUNTRACED);
	}
}
