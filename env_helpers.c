#include "shell.h"


/**
 * _getenv - Gets the value of the environment variable name
 * @name: Environment variable to get the value from
 *
 * Return: The value of the environment name or NULL if couldn't find it
 */
char *_getenv(const char *name)
{
	size_t i, j;
	int is_different = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] == '\0' || name[j] != environ[i][j])
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


/**
 * print_env - Prints the current environment
 *
 * Return: void
 */
void print_env(void)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
