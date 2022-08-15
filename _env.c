#include "shell.h"

/**
 * env_ - function that prints the current environment
 * 
 * Return: void
 */

void print_env(void)
{
	size_t i = 0;
	extern char **environ;


	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
