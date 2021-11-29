#ifndef MAIN
#define MAIN

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>

void free_tow(char **tow);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

size_t _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char **strtow(char *str, char *del);
int _strcmp(char *s1, char *s2);
char *strnon(char *str);


#endif
