#include "monty.h"

/**
 * _strlen - finds length of a string
 * @str: string to be counted
 * Return: length of the string || 0 if fail or empy string
 */
int _strlen(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * _strcmp - compares two strings
 * @s1: fist string to compare
 * @s2: second string to compare
 * Return: if s1 is less, equal or greates than s2 return positive int
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
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
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
			++i;
	}
	else
	{
		return (s1[i] - s2[i]);
	}
	if (i == n && s1[i] == ' ' || s1[i] == '\t' || s1[i] == '\0' || s1[i] == '\n')
		return (0);
	return (EXIT_FAILURE);
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

	while (*s && *s == ' ')
	{
		++s;
	}
	if (*s == '\0')
		return (NULL);

	return (s);
}

/**
 * findNumber - finds a number in a string
 * @s: string to be searched
 * Return: string with numbers || NULL if failed
 */
char *findNumber(char *s)
{
	if (!s)
		return (NULL);

	while (*s && (*s < '0' || *s > 9))
		++s;
	if (*s == '\0')
		return (NULL);

	return (s);
}
