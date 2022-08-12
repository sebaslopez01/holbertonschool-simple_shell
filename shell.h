#ifndef SHELL_H
#define SHELL_H

/* importing */
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/* types and structures */

/* macros valores constantes */

/* prototypes */
int print_error(char *str);
void split_args(char **tokens, char *str, char *delimeter);
int contains_char(char *str, char c);
size_t _strlen(const char *str);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);

/* macros functions */

#endif
