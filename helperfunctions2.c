#include "shell.h"


/**
 * _strcpy - Copies a string
 * @dest: Buffer to copy
 * @src: Source to copy the string
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}
