#include "main.h"


/**
 * prompt - function that prints prompt
 *
 */
void prompt(void)
{
	char *cmd = "";

	isatty(STDIN_FILENO);

	write(STDOUT_FILENO, cmd, _strlen(cmd));
	fflush(stdout);
}
