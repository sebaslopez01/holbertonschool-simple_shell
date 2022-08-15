#include "shell.h"

/**
 * env_ - function that prints the current environment
 * 
 * Return: void
 */

void env_(char **buffer)
{
	int i = 0;
	extern char **environ;
	(void)buffer;


		for (i = 0; environ[i][k]i++)
		write(STDOUT_FILENO, environ[i], _strlen(environ));
		free(buffer);
}
