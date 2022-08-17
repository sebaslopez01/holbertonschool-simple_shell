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


/**
 * _realloc - Reallocates a memory block
 * @ptr: Pointer to memory previously allocated
 * @old_size: Size of ptr
 * @new_size: New size of the new memory block
 *
 * Return: Pointer to the new memory block
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr = NULL;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		free(ptr);
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}

	return (ptr);
}
