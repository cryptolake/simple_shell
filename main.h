#ifndef MAIN
#define MAIN

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

size_t _strlen(const char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *strnon(char *str);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

char *_getenv(const char *name);
char *path_match(char **s);
int is_path(char *s);
int is_dir(char *file);

int _atoi(const char *s);

void run_av(char **av);
void execute_line(char *line);
void err_out(char *name, char *err);

#endif
