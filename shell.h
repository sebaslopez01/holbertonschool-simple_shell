#ifndef SHELL_H
#define SHELL_H

/* importing */
#include <unistd.h>
#include <sys/wait.h>
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

/* macros functions */

#endif
