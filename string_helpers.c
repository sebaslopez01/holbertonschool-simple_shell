#include "shell.h"


/**
 * _strlen - Gets the length of a string
 * @str: String to get the length from
 *
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}


/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Number difference between the two strings
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}


/**
 * reverse_string - Reverses the order of an array of chars
 * @str: Array of chars to reverse
 *
 * Return: void
 */
void reverse_string(char *str)
{
	size_t i, len = _strlen(str);
	char temp;

	for (i = 0; i < len / 2; i++)
	{
		temp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = temp;
	}
}


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


/**
 * _strcat - Concatenates two string
 * @dest: Destination string
 * @src: Source string
 *
 * Return: A pointer to resulting string dest
 */
char *_strcat(char *dest, const char *src)
{
	size_t i, dest_len = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
