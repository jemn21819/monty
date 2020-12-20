#include "monty.h"
#include <ctype.h>

/**
 * searchNumber - finds a number in a string
 * @s: string to be searched
 * Return: string with numbers || NULL if failed
 */

static int searchNumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-' && i == 0)
			continue;
		if (isdigit(s[i]) == 0)
			return (1);
	}
	return (0);
}


/**
 * push - pushes an element to the stack.
 * @head: pointer to the head of double l-list
 * @line_num: line number
 */

void push(stack_t **head, unsigned int line_num)
{
	char *line;
	int n;

	line = strtok(NULL, "\n\t\r ");
	if (line == NULL || searchNumber(line))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	n = atoi(line);
	if (!add_node(head, n))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.head_len++;
}

/**
 * pop - pop value at the top of the stack
 * @head: head of stack
 * @line_num: number of lines
 * Return: no return for void function
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *pop = *head;

	if (var.head_len == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	if (var.head_len != 1)
		*head = (*head)->next;
	else
		*head = NULL;
	free(pop);
	var.head_len--;
}
