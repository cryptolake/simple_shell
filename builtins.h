#ifndef BUILTINS_H_
#define BUILTINS_H_

typedef struct bltn
{
	char *s;
	int (*f)(char **av);

} bltn;

int fenv(char **av);
int fcd(char **av);
int fexit(char **av);


#endif
