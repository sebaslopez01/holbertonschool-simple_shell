#include "shell.h"

/**
 * main - program that executes command line operations
 *
 * Return: 0 Success
 */

int main(void)
{
	pid_t new_process;
	int status = 0, exit_status = 0;
	ssize_t readed_bytes;
	extern char **environ;
	char *buffer = NULL, *prompt = "#cisfun$ ", *tokens[1024];
	size_t bufsize = 0, promptsize = 9;

	while (1)
	{	
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, promptsize);

		readed_bytes = getline(&buffer, &bufsize, stdin);
		if (readed_bytes == EOF)
			break;
		buffer[readed_bytes - 1] = '\0';

		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(exit_status);
		}

		split_args(tokens, buffer, " \t\r\n");

		if (tokens[0] == NULL)
			break;

		new_process = fork();
		if (new_process == EOF)
		{
			free(buffer);
			return (print_error("New process error"));
		}

		if (new_process == 0)
		{
			if (execve(tokens[0], tokens, environ) == EOF)
			{
				free(buffer);
				return (print_error("./shell"));
			}
						
			free(buffer);
			buffer = NULL;
			bufsize = 0;
		}
		else
			wait(&status);

		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}

	free(buffer);

	return (0);
}
