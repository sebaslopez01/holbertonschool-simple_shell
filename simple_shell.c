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
	char *buffer = NULL, *prompt = "#cisfun$ ", *tokens[1024], *cmd = NULL;
	size_t bufsize = 0, promptsize = 9, count_err = 1;

	while (1)
	{	
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, promptsize);
		readed_bytes = getline(&buffer, &bufsize, stdin);
		if (readed_bytes == EOF)
			break;
		if (*buffer == '\n')
			continue;
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(exit_status);
		}

		split_args(tokens, buffer, " \t\r\n");
		if (tokens[0] == NULL)
			break;
		cmd = tokens[0];
		tokens[0] = filter_cmd(cmd);
		if (tokens[0] == NULL)
		{
			print_not_found_error(cmd, &count_err);
			if (!isatty(STDIN_FILENO))
			{
				free(buffer);
				exit(127);
			}
			continue;
		}

		new_process = fork();
		if (new_process == EOF)
		{
			free(tokens[0]);
			free(buffer);
			return (print_error("New process error"));
		}

		if (new_process == 0)
		{
			execve(tokens[0], tokens, environ);

			free(tokens[0]);
			free(buffer);
			return (print_error("./shell"));
		}
		else	
			wait(&status);
		free(tokens[0]);

		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}

	free(buffer);
	
	return (0);
}
