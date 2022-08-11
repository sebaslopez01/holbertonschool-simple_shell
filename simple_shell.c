#include "shell.h"

/**
 * main - program that executes command line operations
 *
 * Return: 0 Success
 */

int main(void)
{
	pid_t new_process;
	int status;
	ssize_t readed_bytes;
	extern char **environ;
	char *buffer = NULL, *argv[1024], *prompt = "#cisfun$ ";
	char *tokens[1024], *tokens_args[1024];
	size_t i, bufsize, promptsize = 9;

	while (1)
	{	
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, promptsize);

		readed_bytes = getline(&buffer, &bufsize, stdin);
		if (readed_bytes == EOF)
			break;
		buffer[readed_bytes - 1] = '\0';

		new_process = fork();
		if (new_process == EOF)
		{
			free(buffer);
			return (print_error("New process error"));
		}

		if (new_process == 0)
		{	
			split_args(tokens, buffer, "\n");

			for (i = 0; tokens[i] != NULL; i++)
			{
				if (!contains_char(tokens[i], ' '))
				{
					argv[0] = tokens[i];
					argv[1] = NULL;
					if (execve(argv[0], argv, environ) == EOF)
					{
						free(buffer);
						return (print_error("./shell"));
					}
				}
				else
				{
					split_args(tokens_args, tokens[i], " ");
					if (tokens_args[0] == NULL)
					{
						free(buffer);
						return (0);
					}

					if (execve(tokens_args[0], tokens_args, environ) == EOF)
					{
						free(buffer);
						return (print_error("./shell"));
					}
				}
			}
			
			free(buffer);
			buffer = NULL;
			bufsize = 0;
		}
		else	
			wait(&status);
	}

	free(buffer);

	return (0);
}
