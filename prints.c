#include "monty.h"

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
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pchar - prints the char at the top of the stack.
 * @head: pointer to double l-list
 * @line_num: line number
 */

void pchar(stack_t **head, unsigned int line_num)
{
	int letter;

	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}

	letter = (*head)->n;
	if (letter < 0 || letter > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", letter);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to double l-list
 * @line_num: void
 */

void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void) line_num;

	h = *head;
	while (h)
	{
		if (h->n > 32 && h->n < 127)
			printf("%c", h->n);
		else
			h = h->next;
	}
	printf("\n");
}
