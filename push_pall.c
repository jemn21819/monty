#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @head: pointer to the head of double l-list
 * @line: content in file
 * @line_num: line number
 */

 void push(stack_t **head, char *line, unsigned int line_num)
{
	char *first_n;
	stack_t *node;

	first_n = searchNumber(line);
	if (!first_n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free(line);
		free(*head);
		*head = NULL;
		exit(EXIT_FAILURE);
	}
	node = add_node(head, atoi(first_n));
	if (!node)
	{
		puts("Error: malloc failed");
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	free(line);
}

/**
 * pall - prints all elents in a stack from top
 * @head: head of the stack
 * @line_num: number of lines
 * Return: no return for print function
 */

void pall(stack_t **head, unsigned int line_num)
{
	(void)line_num;
	stack_t *h = *head;

	if (head == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
