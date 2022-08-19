#include "shell.h"


/**
 * create_process - Creates a child process to execute a program
 * @program_name: Name of the program
 * @buffer: String readed from stdin
 * @tokens: Array of arguments
 *
 * Return: Exit status code
 */
int create_process(char *program_name, char *buffer, char **tokens)
{
	pid_t new_process;
	int status = 0, exit_status = 0;

	new_process = fork();
	if (new_process == EOF)
	{
		free_tokens(tokens);
		free(buffer);

		exit(print_error(program_name));
	}

	if (new_process == 0)
	{
		execve(tokens[0], tokens, environ);

		free_tokens(tokens);
		free(buffer);

		exit(print_error(program_name));
	}
	else
		wait(&status);

	free_tokens(tokens);

	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);

	return (exit_status);
}


/**
 * create_tokens - Creates an array of arguments
 * @program_name: Program Name executing
 * @buffer: String readed from the stdin
 * @count_err: Pointer to an error counter
 *
 * Return: Pointer to an array of arguments, or NULL if it failed
 */
char **create_tokens(char *program_name, char *buffer, size_t *count_err)
{
	char **tokens = NULL;

	tokens = split_args(buffer, " \t\r\n");
	if (tokens == NULL || tokens[0] == NULL)
	{
		free_tokens(tokens);

		return (NULL);
	}

	if (!filter_cmd(&tokens[0]))
	{
		print_not_found_error(program_name, tokens[0], count_err);

		free_tokens(tokens);

		if (!isatty(STDIN_FILENO))
		{
			free(buffer);
			exit(127);
		}

		return (NULL);
	}

	return (tokens);
}


/**
 * execute_builtins - Executes the builtins functions of the shell
 * @buffer: String readed from stdin
 * @exit_status: Exit status code of program
 *
 * Return: 1 for success, 0 otherwise
 */
int execute_builtins(char *buffer, int exit_status)
{
	if (!_strcmp(buffer, "exit\n"))
	{
		free(buffer);

		exit(exit_status);
	}

	if (!_strcmp(buffer, "env\n"))
	{
		print_env();

		return (0);
	}

	return (1);
}

