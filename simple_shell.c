#include "shell.h"


char *filter_cmd(char *cmd)
{
	char *token = NULL, *p_cmd = NULL, *p_data = _getenv("PATH"), *p_copy = NULL;
	size_t i, j, cmd_len = _strlen(cmd);
	
	if (p_data == NULL)
		return (NULL);
	p_cmd = malloc(sizeof(char) * cmd_len + 1);
	if (!p_cmd)
		return (NULL);
	p_cmd = _strcpy(p_cmd, cmd);
	if (access(p_cmd, F_OK) == 0)
		return (p_cmd);
	free(p_cmd);
		
	p_copy = malloc(sizeof(char) * _strlen(p_data) + 1);
	if (!p_copy)
		return (NULL);
	p_copy = _strcpy(p_copy, p_data);
	token = strtok(p_copy, ":");
	while (token != NULL)
	{
		p_cmd = malloc(sizeof(char) * _strlen(token) + cmd_len + 2);
		if (!p_cmd)
			return (NULL);
		_strcpy(p_cmd, token);
		_strcat(p_cmd, "/");
		_strcat(p_cmd, cmd);

		if (access(p_cmd, F_OK) == 0)
		{
			free(p_copy);
			return (p_cmd);
		}
		token = strtok(NULL, ":");
		free(p_cmd);
	}
	free(p_copy);
	return (NULL);
}


void print_not_found_error(char *cmd, size_t *count_err)
{
	char *num = NULL, *error_msg = NULL;
	size_t len;
	
	num = malloc(sizeof(char) * count_digits(*count_err) + 1);
	if (!num)
		return;
	num = itoa(*count_err, num);
	len = _strlen(cmd) + _strlen(num) + 21;

	error_msg = malloc(sizeof(char) * len + 1);
	if (!error_msg)
		return;

	_strcpy(error_msg, "./hsh: ");
	_strcat(error_msg, num);
	_strcat(error_msg, ": ");
	_strcat(error_msg, cmd);
	_strcat(error_msg, ": not found\n");

	write(STDERR_FILENO, error_msg, len);
	
	free(num);
	free(error_msg);
}


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
		if (isatty(STDIN_FILENO) == 1)
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
