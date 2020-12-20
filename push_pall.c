#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @head: pointer to the head of double l-list
 * @line: content in file
 * @line_num: line number
 * Return: 0 on success -1 on failure
 */

int push(stack_t **head, char *line, unsigned int line_num)
{
	char *first_n;
	stack_t *node;

	first_n = searchNumber(line);
	if (!first_n)
	{
		printf("L%d: usage: push integer\n", line_num);
		free(line);
		exit(EXIT_FAILURE);
	};

	if (_strcmp(flag, "stack") == 0)
		node = add_node(head, atoi(first_n));
	else
		node = add_node_end(head, atoi(first_n));

	free(line);
	if (!node)
	{
		puts("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * pall - prints all elents in a stack from top
 * @head: head of the stack
 * @line_num: number of lines
 * Return: no return for void function
 */

void pall(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	if (head == NULL)
		return;
	h = *head;
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
	stack_t *node;

	node = pop_start(head);

	if (!node)
	{
		printf("L%d: can't pop an empty stack", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	free(node);
}
