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

/* global variables */
extern char **environ;

/* prototypes */
int print_error(char *str);
size_t count_args(const char *str, const char *delimeter);
char **split_args(char *str, const char *delimeter);
void free_tokens(char **tokens);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
void reverse_string(char *str);
char *itoa(int num, char *buffer);
size_t count_digits(int num);
void print_not_found_error(char *program_name, char *cmd, size_t *count_err);
int filter_cmd(char **cmd);
void print_env(void);
void *_calloc(size_t nelem, size_t elsize);
void *_memset(void *s, int c, size_t n);
int create_process(char *program_name, char *buffer, char **tokens);
char **create_tokens(char *program_name, char *buffer, size_t *count_err);
int execute_builtins(char *buffer, int exit_status);

#endif
