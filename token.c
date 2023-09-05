#include "main.h"

/**
 * tokenize - function to split strings
 * @input: input string
 * @delim: delimiter to tokenize
 *
 * Return: array of strings containing token
 */
char **tokenize(char **input, const char *delim)
{
	static char *tokens[50];
	/*	char **tokens = malloc(1024 * sizeof(char*));*/
	/*	char *tokens[1024];*/
	int numTokens = 0;
	char *token;

	token = strtok(*input, delim);
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		/*tokens[numTokens] = token;*/
		tokens[numTokens] = token;
		if (tokens[numTokens][0] == '#')
		{
			tokens[numTokens] = NULL;
			break;
		}
		numTokens++;
		token = strtok(NULL, delim);
	}
	return (tokens);

}

/**
 * free_tokens - function to free tokens used
 * @tokens: strings to be freed
 *
 * Return: free tokens
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (!tokens)
	{
		return;
	}

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
