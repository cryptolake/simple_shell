#ifndef BUILTINS_H_
#define BUILTINS_H_

/**
 * struct bltn - shell builtins
 * @s: name of builtin
 * @f: function of builtin
 *
 **/
typedef struct bltn
{
	char *s;
	int (*f)(char **av);

} bltn;

int fenv(char **av);
int fcd(char **av);
int fexit(char **av);


#endif
