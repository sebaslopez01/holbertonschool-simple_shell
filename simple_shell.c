#include "shell.h"

/**
 *
 *
 */

int print_error(char *str)
{
	perror(str);
	
	return (1);
}

int main(void)
{
	pid_t new_process;
	int status;
	ssize_t readed_bytes;
	extern char **environ;
	char *buffer = NULL, *argv[2], *prompt = "#cisfun$ ";
	size_t bufsize, promptsize = 9;

	while (1)
	{	
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, promptsize);
		readed_bytes = getline(&buffer, &bufsize, stdin);
		if (readed_bytes == EOF)
			break;

		buffer[readed_bytes - 1] = '\0';
		argv[0] = buffer;
		argv[1] = NULL;

		new_process = fork();
		if (new_process == EOF)
		{
			free(buffer);
			return(print_error("New process error"));
		}

		if (new_process == 0)
		{		
			if (execve(buffer, argv, environ) == EOF)
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

		if (isatty(STDIN_FILENO) == 0)
			break;
	}

	free(buffer);

	return (0);
}
