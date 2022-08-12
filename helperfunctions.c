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
 * contains_char - function that searches for a specific character in a string
 * @str: string in which the character is searched
 * @c: character to search
 * Return: 0 Success
 */

int contains_char(char *str, char c)
{
	size_t i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return (1);
	}

	return (0);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Number difference between the two strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	return (*s1 - *s2);
}
