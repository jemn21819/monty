#include "str_hdr.h"

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
	int count = 0;

	while (s1[count] == s2[count] && s1 != '\0')
	{
		count++;
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
	int count = 0;

	while (n > 0)
	{
		if (s1[count] != s2[count])
		{
			return (*s1 - *s2);
		}
		count++;
	}
	return (0);
}
