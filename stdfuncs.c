#include "main.h"

/**
* _abs - return absolute value
* @n: number
*
* Return: absolute value
**/
int _abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}


/**
 * count_d10 - count number of digits
 *
 * @n: number
 *
 * Return: 10^count-1
 **/
int count_d10(int n)
{
	int x;

	x = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		x *= 10;
	}
	return (x);
}


/**
 * _itoa - int to str
 *
 * @n: number
 * Return: string
 **/
char *_itoa(int n)
{
	char *s;
	int x = 0,
	y = 0,
	c = 0,
	i = 0,
	b = _abs(n),
	l = 0,
	e = 1;

	while (b != 0)
	{
		b /= 10;
		l++;
	}

	x = count_d10(n);
	if (n < 0)
	{
		y = 1;
		e = -1;
	}

	s = malloc(sizeof(char) * (l + y + 1));
	if (s == NULL)
		return (NULL);

	if (n < 0)
		s[i++] = '-';

	while (x != 0)
	{
		c = e * ((n / x) % 10) + '0';
		x /= 10;
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return (s);
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
