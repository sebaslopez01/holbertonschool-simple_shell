#include "shell.h"


/**
 * count_digits - Count number of digits of a number
 * @num: Number to count
 *
 * Return: Number of digits
 */
size_t count_digits(int num)
{
	size_t num_digits = 0;

	if (num < 0)
		num_digits++;

	for (; num != 0; num_digits++)
		num /= 10;

	return (num_digits);
}


/**
 * itoa - Fill a buffer of chars with a long int value
 * @num: Number to convert to a string
 * @buffer: Buffer to fill
 *
 * Return: Number converted to string
 */
char *itoa(int num, char *buffer)
{
	int digit, temp_num = num;
	size_t count = 0;

	if (num == 0)
	{
		buffer[count++] = '0';
		buffer[count] = '\0';
		return (buffer);
	}

	while (temp_num != 0)
	{
		digit = temp_num % 10;

		if (digit < 0)
			digit *= -1;

		buffer[count++] = digit + '0';

		temp_num /= 10;
	}

	if (num < 0)
		buffer[count++] = '-';

	buffer[count] = '\0';

	reverse_string(buffer);

	return (buffer);
}
