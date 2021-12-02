#include "main.h"

/**
 * isn - check if character a number or not
 *
 * @c: character
 *
 * Return: 1 number, 0 not a number
 **/
int isn(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * sign - return the sign of string before a number
 *
 * @s: string
 * @l: length of string
 *
 * Return: 1 positive, -1 negative
 **/
int sign(const char *s, int l)
{
	int i, n;

	n = 1;

	i = 0;
	while (!(isn(s[i])) && i <= l)
	{
		if (s[i] == '-')
		{
			n = -n;
		}
		i++;
	}
	return (n);
}


/**
 * numl - get the length of the number inside a string
 * @s: string
 * @i: first index of the number
 *
 * Return: index of the last digit of number
 **/
int numl(const char *s, int i)
{
	while (isn(s[i]))
	{
		i++;
	}
	return (i);
}

/**
* _atoi - convert number in string to int
*
* @s: string
*
* Return: number
**/
int _atoi(const char *s)
{
	int n;
	int l, i, j;
	int k;
	int f;

	l = _strlen(s);
	n = 0;
	f = 0;

	for (i = 0; i < l && f == 0; i++)
	{
		if (isn(s[i]))
		{
			f = 1;
		}

	}

	if (f)
	{
		i--;
		k = sign(s, l);
		for (j = i; j <= numl(s, i) - 1; j++)
		{
			n = n + k * (s[j] - '0');
			if (j < numl(s, i) - 1)
				n *= 10;
		}
		return (n);
	}
	else
	{
		return (0);
	}
}


/**
 * swap - swap two variables
 *
 * @a: first var
 * @b: second var
 **/
void swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}


/**
 * rev_string - reverse string
 *
 * @s: string
 *
 * Return: string reversed
 **/
char *rev_string(char *s)
{
	int n = _strlen(s);
	int i;

	for (i = 0; i < n / 2; i++)
		swap(&s[i], &s[n - i - 1]);

	return (s);
}
