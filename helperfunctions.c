#include "shell.h"

/**
 * print_error - print a system error message
 * @str: string of message
 * Return: 1 error value
 */
int print_error(char *str)
{
	perror(str);

	return (1);
}


/**
 * split_args - function that splits the supplied arguments into a string
 * @tokens: pointer to buffer of arguments
 * @str: the string to be parsed
 * @delimeter: tipe of delimeter
 * Return: void
 */
void split_args(char **tokens, char *str, char *delimeter)
{
	char *token = NULL;
	size_t i = 0;

	token = strtok(str, delimeter);

	while (token != NULL)
	{
		tokens[i++] = token;

		token = strtok(NULL, delimeter);
	}

	tokens[i] = NULL;
}

/**
 * _strlen - Gets the length of a string
 * @str: String to get the length from
 *
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}


/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Number difference between the two strings
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}


/**
 * _getenv - Gets the value of the environment variable name
 * @name: Environment variable to get the value from
 *
 * Return: The value of the environment name or NULL if couldn't find it
 */
char *_getenv(const char *name)
{
	extern char **environ;
	size_t i, j;
	int is_different = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				is_different = 1;
				break;
			}
		}

		if (!is_different)
			return (*(environ + i) + j + 1);

		is_different = 0;
	}

	return (NULL);
}
