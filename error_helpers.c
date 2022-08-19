#include "shell.h"


/**
 * print_error - print a system error message
 * @str: string of message
 * Return: 1 error value
 */
int print_error(char *str)
{
	perror(str);

	return (1);
}


/**
 * print_not_found_error - Prints an error if a command is not found
 * @program_name: Program Name executing
 * @cmd: Name of the command to print
 * @count_err: Number of errors to increment
 *
 * Return: void
 */
void print_not_found_error(char *program_name, char *cmd, size_t *count_err)
{
	char *num = NULL, *error_msg = NULL;
	size_t len;

	num = malloc(sizeof(char) * count_digits(*count_err) + 1);
	if (!num)
		return;
	num = itoa(*count_err, num);
	len = _strlen(cmd) + _strlen(num) + _strlen(program_name) + 16;

	error_msg = malloc(sizeof(char) * len + 1);
	if (!error_msg)
		return;

	_strcpy(error_msg, program_name);
	_strcat(error_msg, ": ");
	_strcat(error_msg, num);
	_strcat(error_msg, ": ");
	_strcat(error_msg, cmd);
	_strcat(error_msg, ": not found\n");

	write(STDERR_FILENO, error_msg, len);

	(*count_err)++;
	free(num);
	free(error_msg);
}
