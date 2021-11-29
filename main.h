#ifndef STRTOW_H_
#define STRTOW_H_

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>

void free_tow(char **tow);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _strlen(const char *s);
char **strtow(char *str, char del);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif
