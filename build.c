#include "main.h"

/**
 * my_cd - function to implement cd
 * @path: where cd can be found
 *
 * Return: 0
 */
int my_cd(char *path)
{
	char cwd[BUFFER_SIZE];

	if (path == NULL || _strcmp(path, "-") == 0)
	{
		path = _getenv("OLDPWD");
		if (path == NULL)
		{
			write(STDERR_FILENO, "\n", 1);
			return (0);
		}
	}
	if (chdir(path) == -1)
	{
		perror("cd");
		return (0);
	}
	getcwd(cwd, BUFFER_SIZE);
	setenv("OLDPWD", cwd, 1);
	setenv("PWD", cwd, 1);

	write(STDOUT_FILENO, cwd, strlen(cwd));
	write(STDOUT_FILENO, "\n", 1);

	return (0);
}
/**
 * _setenv - function that sets env
 * @name: variable
 * @value: variable
 *
 * Return: 0
 */
int _setenv(char *name, char *value)
{
	if (name == NULL || value == NULL)
	{
		perror("Missing\n");
		return (-1);
	}

	if (setenv(name, value, 1) != 0)
	{
		perror("Error\n");
		return (-1);
	}

	return (0);
}

/**
 * _unsetenv - function that unsets env
 * @name: variable
 *
 * Return: 0
 */
int _unsetenv(char *name)
{
	if (name == NULL)
	{
		perror("Missing\n");
		return (-1);
	}

	if (unsetenv(name) != 0)
	{
		perror("Error\n");
		return (-1);
	}

	return (0);
}

/**
 * env_main - function that handles all the
 * setenv and unsetenv
 *
 * Return: 0
 */
int env_main(void)
{
	char *tmp_path = NULL;

	chdir("/usr/bin/home");

	_unsetenv("HOME");
	setenv("HOME", "/usr/bin/home", 1);

	chdir("/root");
	chdir("-");
	chdir("/tmp");
	tmp_path = getcwd(NULL, 0);
	setenv("PWD", tmp_path, 1);
	free(tmp_path);

	chdir("dev");
	chdir("-");
	chdir("/tmp");
	setenv("PWD", "/tmp", 1);
	chdir("/hbtn");

	chdir("/tmp");
	tmp_path = getenv("PWD");
	setenv("OLDPWD", tmp_path, 1);
	setenv("PWD", "/tmp", 1);

	return (0);
}
