#include "main.h"

/**
 * get_line - function that reads input
 *
 * Return: line to read on success, NULL if failure
 */
char *get_line(void)
{
	static char line[BUFFER_SIZE];
	size_t index = 0;
	static char buffer[BUFFER_SIZE];
	size_t i;
	char t_char;
	static ssize_t rd;

	rd = read(STDIN_FILENO, buffer, BUFFER_SIZE);

	if (rd == -1 || rd == 0)
	{
		return (NULL);
	}

	for (i = 0; i < (size_t)rd; i++)
	{
		t_char = buffer[i];
		if (t_char == '\n')
		{
			line[index] = '\0';
			return (line);
		}
		line[index++] = t_char;
	}

	return (line);
}
