#include "shell.h"
#include <errno.h>

int print_err(void)
{
	char *msg = "Fuck you!\n";
	int ret = 127;

	write(STDERR_FILENO, msg, _strlen(msg));

	return (ret);
}


int main()
{
	int ret = 0;

	if (access("hola", F_OK) == 0)
		printf("Ok\n");
	else
		ret = print_err();

	return (0);
}
