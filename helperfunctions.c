#include "shell.h"


/**
 * free_tokens - Frees space of all tokens and the array itself
 * @tokens: Tokens to free
 *
 * Return void
 */
void free_tokens(char **tokens)
{
	size_t i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);

	free(tokens);
}


/**
 * count_args - Count the number of arguments a string have
 * by it delimiter
 * @str: String to count arguments
 * @delimeter: Delimeter to use to count
 *
 * Return: Number of arguments of a string
 */
size_t count_args(const char *str, const char *delimeter)
{
	char *str_copy = NULL, *token = NULL;
	size_t count = 0;

	str_copy = _strdup(str);
	if (str_copy == NULL)
		return (0);

	token = strtok(str_copy, delimeter);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delimeter);
	}

	free(str_copy);

	return (count);
}


/**
 * split_args - Splits a string in an array of arguments
 * @str: The string to be parsed
 * @delimeter: Delimeter to use
 *
 * Return: Pointer to an array of arguments
 */
char **split_args(char *str, const char *delimeter)
{
	char **tokens = NULL, *token = NULL;
	size_t i = 0, j, count;

	count = count_args(str, delimeter);
	if (count == 0)
		return (NULL);

	tokens = _calloc(count + 1, sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(str, delimeter);

	while (token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (!tokens[i])
		{
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			return (NULL);
		}

		_strcpy(tokens[i++], token);

		token = strtok(NULL, delimeter);
	}

	return (tokens);
}


/**
 * filter_cmd - Filters a command in the PATH
 * @cmd: String to filter in the PATH
 *
 * Return: 1 if the command were filtered,
 * 0 if the command were not filtered,
 * -1 if an error occured
 */
int filter_cmd(char **cmd)
{
	char *token = NULL, *p_cmd = NULL, *p_data = _getenv("PATH"), *p_copy = NULL;
	size_t cmd_full_len, cmd_len = _strlen(*cmd);

	if ((*cmd[0] != '/' && *cmd[0] != '.') && p_data == NULL)
		return (0);
	if (access(*cmd, F_OK) == 0)
		return (1);

	p_copy = _strdup(p_data);
	if (!p_copy)
		return (-1);

	token = strtok(p_copy, ":");
	while (token != NULL)
	{
		cmd_full_len = _strlen(token) + cmd_len + 1;
		p_cmd = malloc(sizeof(char) * cmd_full_len + 1);
		if (!p_cmd)
			return (-1);
		_strcpy(p_cmd, token);
		_strcat(p_cmd, "/");
		_strcat(p_cmd, *cmd);

		if (access(p_cmd, F_OK) == 0)
		{
			free(*cmd);
			*cmd = p_cmd;
			free(p_copy);
			return (1);
		}
		token = strtok(NULL, ":");
		free(p_cmd);
	}

	free(p_copy);
	return (0);
}
