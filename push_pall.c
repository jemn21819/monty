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
 * Return: no return for void function
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

/**
 * pint - prints value at the top of the stack
 * @head: head of stack
 * @line_num: number of lines
 * Return: no return for void function
 */
void pint(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pint, stack empty", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - pop value at the top of the stack
 * @head: head of stack
 * @line_num: number of lines
 * Return: no return for void function
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pop an empty stack", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	free_stk(temp);
}
