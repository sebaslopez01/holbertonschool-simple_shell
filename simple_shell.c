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
	char *buffer = NULL, *argv[2];
	size_t bufsize = 0;

	while (1)
	{
		printf("#cisfun$ ");
		readed_bytes = getline(&buffer, &bufsize, stdin);
		if (readed_bytes == -1)
			return (0);

		buffer[readed_bytes - 1] = '\0';
		argv[0] = buffer;
		argv[1] = NULL;
	
		new_process = fork();
		if (new_process == EOF)
			return(print_error("New process error"));

		if (new_process == 0)
		{
			if (execve(buffer, argv, NULL) == EOF)
				return (print_error("./shell"));
		}
		else
			wait(&status);
	}
	
	return (0);
}
