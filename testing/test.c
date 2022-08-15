#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int print_err(void)
{
	char *msg = "Fuck you!\n";
	int ret = 127;

	write(STDERR_FILENO, msg, strlen(msg));

	return (ret);
}


int main()
{
	int ret = 0;
	struct stat st;

	if (stat("hbtn_ls", &st) == 0)
		printf("Ok\n");
	else
		ret = print_err();

	return (0);
}
