#ifndef STRTOW_H_
#define STRTOW_H_
#include <stddef.h>

char **strtow(const char *str, const char del);
void free_tow(char **tow);
size_t len_tow(char **av);
void print_tow(char **tow);

#endif
