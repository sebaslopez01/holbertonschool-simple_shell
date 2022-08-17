#include "shell.h"


/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 *
 * Return: Pointer to the new string duplicated from str
 * or NULL if it failes to allocate the new memory
 */
char *_strdup(const char *str)
{
	char *new_str = NULL;

	new_str = malloc(sizeof(char) * _strlen(str) + 1);
	if (!new_str)
		return (NULL);

	_strcpy(new_str, str);

	return (new_str);
}



