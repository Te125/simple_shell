#include "main.h"

void main_l(char *envp[]);
/**
 * main - function with arguments
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 *
 * Return: nothing
 */
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;

	main_l(envp);

	return (EXIT_SUCCESS);
}

/**
 * main_l - function to loop
 * @envp: environment array
 * Return: nothing
 */
void main_l(char *envp[])
{
	char *buf = NULL, **tokens = NULL;
	ssize_t args;
	size_t buf_size = 0;

	while (1)
	{
		prompt();
		args = getline(&buf, &buf_size, stdin);
		if (args == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("Error in input");
				free(buf);
				exit(0);
			}
		}
		buf[strcspn(buf, "\n")] = '\0';
		tokens = tokenize(&buf, "; \t\r\n\a");
		if (!tokens[0])
		{
			/*perror("Error");*/
			continue;
		}
		else
		{
		if (tokens[0])
		{
			if (_strcmp(tokens[0], "exit") == 0)
			{
				free(buf);
				my_exit((const char * const *)tokens);
			}
			if (_strcmp(tokens[0], "env") == 0)
			{
				my_env(envp);
			}
			else
				execve_func(tokens, envp);
		}
	}
	free(buf);
	exit(EXIT_SUCCESS);
	}
}
