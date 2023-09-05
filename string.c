#include "main.h"

/**
 * _strcat - functions to concatenates two strings
 * @d: destination
 * @s: source
 *
 * Return: pointer to string
 */
char *_strcat(char *d, const char *s)
{
	int n = 0, j = 0;

	while (d[n])
	{
		n++;
	}
	while (s[j])
	{
		d[n] = s[j];
		n++;
		j++;
	}
	d[n] = '\0';
	return (d);
}


/**
 * _strcmp - function to compare two strings
 * @d1: input
 * @d2: input
 *
 * Return: *d1 - *d2
 */
int _strcmp(const char *d1, const char *d2)
{
	while (*d1 && *d2 && *d1 == *d2)
	{
		d1++;
		d2++;
	}
	return (*d1 - *d2);
}

/**
 * _strcpy - function that copies strings
 * @dest: copy to
 * @src: copy from
 *
 * Return: pointer to copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return  (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}


/**
 * _strdup - fuunction that duplicates strings
 * @st: string to duplicate
 *
 * Return: pointer to space in memory
 */
char *_strdup(const char *st)
{
	char *dp = 0;
	int n = 0, t = 0;

	if (st == NULL)
	{
		return (NULL);
	}

	while (st[t] != '\0')
	{
		t++;
	}
	dp = malloc(sizeof(char) * (t + 1));

	if (dp == NULL)
	{
		return (NULL);
	}
	for (n = 0; n < t; n++)
	{
		dp[n] = st[n];
	}
	dp[t] = '\0';

	return (dp);
}


/**
 * _strlen - returns length of string
 * @s: string
 *
 * Return: length
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len])
	{
		len++;
	}
	return (len);
}
