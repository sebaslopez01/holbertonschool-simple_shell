#include "shell.h"


/**
 * main - Executes command line operations
 * @argc: Size of argv
 * @argv: Array of arguments
 *
 * Return: 0 Success
 */
int main(int argc, char **argv)
{
	int builtins_res, exit_status = 0;
	ssize_t readed_bytes;
	char *buffer = NULL, *prompt = "#cisfun$ ", **tokens = NULL;
	size_t bufsize = 0, promptsize = 9, count_err = 1;

	if (argc > 1)
	{
		write(STDOUT_FILENO, "This program doesn't receive any arguments", 42);
		return (0);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, promptsize);
		readed_bytes = getline(&buffer, &bufsize, stdin);
		if (readed_bytes == EOF)
			break;
		if (*buffer == '\n')
			continue;

		builtins_res = execute_builtins(buffer, exit_status);
		if (!builtins_res)
			continue;

		tokens = create_tokens(argv[0], buffer, &count_err);
		if (tokens == NULL)
			continue;

		exit_status = create_process(argv[0], buffer, tokens);
	}

	free(buffer);

	return (0);
}
