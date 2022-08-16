#include "shell.h"

/**
 * print_env - function that prints the current environment
 * 
 * Return: void
 */

void print_env(void)
{
	extern char **environ;
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * env_check - checks if command is environ
 * @user_input: string to compare to 'env'
 *
 * Return: 1 if string is equal to 'env', otherwise 0
 */

int env_check(char *buffer)
{
	int i = 0;
	char *env = "env";

	if (_strlen(buffer) != 4)
		return (0);

	while (env[i] != '\0')
	{
		if (env[i] != buffer[i])
			return (0);
		i++;
	}
	return (1);
}
