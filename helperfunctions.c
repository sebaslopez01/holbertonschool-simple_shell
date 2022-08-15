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
 * split_args - function that splits the supplied arguments into a string
 * @tokens: pointer to buffer of arguments
 * @str: the string to be parsed
 * @delimeter: tipe of delimeter
 * Return: void
 */
void split_args(char **tokens, char *str, char *delimeter)
{
	char *token = NULL;
	size_t i = 0;

	token = strtok(str, delimeter);

	while (token != NULL)
	{
		tokens[i++] = token;

		token = strtok(NULL, delimeter);
	}

	tokens[i] = NULL;
}


/**
 * _getenv - Gets the value of the environment variable name
 * @name: Environment variable to get the value from
 *
 * Return: The value of the environment name or NULL if couldn't find it
 */
char *_getenv(const char *name)
{
	extern char **environ;
	size_t i, j;
	int is_different = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] == '\0' || name[j] != environ[i][j])
			{
				is_different = 1;
				break;
			}
		}
		if (!is_different)
			return (*(environ + i) + j + 1);

		is_different = 0;
	}

	return (NULL);
}

/**
 * filter_cmd - funtion that filter the command of the PATH
 * @cmd:  string  of the commands imput
 * Return:  NULL
 */
 

char *filter_cmd(char *cmd)
{
	char *token = NULL, *p_cmd = NULL, *p_data = _getenv("PATH"), *p_copy = NULL;
	size_t cmd_len = _strlen(cmd);
	
	if ((cmd[0] != '/' && cmd[0] != '.') && p_data == NULL)
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
