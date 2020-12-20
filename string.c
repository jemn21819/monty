#include "monty.h"

/**
 * _strlen - finds length of a string
 * @str: string to be counted
 * Return: length of the string || 0 if fail or empy string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; *(str + i); ++i)
		;
	return (i);
}

/**
 * skipSpaces - skips whitespaces
 * @s: string to check
 * Return: string withouth spaces
 */

char *skipSpaces(char *s)
{
	if (!s)
		return (NULL);

	while (*s && (*s == ' ' || *s == '\t' || *s == '\v'))
		++s;
	if (*s == '\0' || *s == '\n' || *s == '#')
		return (NULL);
	return (s);
}

/**
 * searchNumber - finds a number in a string
 * @s: string to be searched
 * Return: string with numbers || NULL if failed
 */

char *searchNumber(char *s)
{
	char *c;
	int res, i, neg = 1;

	res = i = 0;
	if (!s)
		return (NULL);

	while (*s && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			neg = -1;
		i++;
		++s;
	}

	if (*s == '\0')
		return (NULL);
	c = s;
	while (*c && *c >= '0' && *c <= '9')
		c++;

	if (!(*c == '\0' || *c == '\n' || *c == ' ' || *c == '\t'))
	return (NULL);

	res = atoi(s) * neg;
	if (res < 0)
	{
		s[i - 1] = '-';
		return (s - 1);
	}
	return (s);
}

/**
 * _strcmp - compares two strings
 * @s1: fist string to compare
 * @s2: second string to compare
 * Return: if s1 is less, equal or greates than s2 return positive int
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0')
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/**
 * _strncmp - compares two strings up to n ammount of chars of s1 in s2
 * @s1: string to compare
 * @s2: string to compare into
 * @n: amount of bytes to compare
 * Return: if s1 is less, equal or greate than s2 return positive int || 0 if
 * fail
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
		{
			++i;
		}
		else
		{
			return (*(s1 + i) - *(s2 + i));
		}
	}
	if (i == n && (*(s1 + i) == ' ' || *(s1 + i) == '\t' ||
		       *(s1 + i) == '\0' || *(s1 + i) == '\n'))
		return (0);
	return (EXIT_FAILURE);
}
