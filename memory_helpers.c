#include "shell.h"

/**
 * _memset - Fills the first n bytes of the memory area
 * with a constant byte
 * @s: Memory area
 * @c: Constant byte
 * @n: Count of bytes to fill
 *
 * Return: A pointer to the memory area s
 */
void *_memset(void *s, int c, size_t n)
{
	unsigned char *p = s;

	while (n--)
		*p++ = (unsigned char) c;

	return (s);
}


/**
 * _calloc - Allocates memory for an array
 * @nelem: Number of elements to allocate
 * @elsize: Size of the element type to allocate
 *
 * Return: A pointer to the allocated memory
 */
void *_calloc(size_t nelem, size_t elsize)
{
	void *p = NULL;

	if (nelem == 0 || elsize == 0)
		return (NULL);

	p = malloc(elsize * nelem);

	if (!p)
		return (NULL);

	_memset(p, 0, elsize * nelem);

	return (p);
}
